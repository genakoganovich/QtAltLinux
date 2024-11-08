#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settingsdialog.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), mSettingsDialog(new SettingsDialog(this))
{
    ui->setupUi(this);
    ui->actionUndo->setShortcut(QKeySequence::Undo);
    ui->actionRedo->setShortcut(QKeySequence::Redo);
    ui->actionCut->setShortcut(QKeySequence::Cut);
    ui->actionCopy->setShortcut(QKeySequence::Copy);
    ui->actionPaste->setShortcut(QKeySequence::Paste);
    ui->actionSelectAll->setShortcut(QKeySequence::SelectAll);
    ui->actionNew->setShortcut(QKeySequence::New);
    ui->actionOpen->setShortcut(QKeySequence::Open);
    ui->actionSave->setShortcut(QKeySequence::Save);
    ui->actionExit->setShortcut(QKeySequence::Quit);
    ui->actionPreferences->setShortcut(QKeySequence::Preferences);


    connect(ui->actionNew, SIGNAL(triggered()),this, SLOT(slotNew()), Qt::UniqueConnection);
    slotNew();

    //Присоединяем действия к созданным слотам
    connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(slotNew()), Qt::UniqueConnection);
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(slotOpen()), Qt::UniqueConnection);
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(slotSave()), Qt::UniqueConnection);
    connect(ui->actionAboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()), Qt::UniqueConnection);
    connect(ui->actionAboutProgram, SIGNAL(triggered()), this, SLOT(slotAboutProgram()), Qt::UniqueConnection);
    connect(ui->actionPreferences, SIGNAL(triggered()), this, SLOT(showPreferencesDialog()), Qt::UniqueConnection);

    ui->actionUndo->setIcon(QIcon(":/actions/undo"));
    ui->actionRedo->setIcon(QIcon(":/actions/redo"));
    ui->actionCut->setIcon(QIcon(":/actions/cut"));
    ui->actionCopy->setIcon(QIcon(":/actions/copy"));
    ui->actionPaste->setIcon(QIcon(":/actions/paste"));
    ui->actionSelectAll->setIcon(QIcon(":/actions/select_all"));
    ui->actionNew->setIcon(QIcon(":/actions/new"));
    ui->actionOpen->setIcon(QIcon(":/actions/open"));
    ui->actionSave->setIcon(QIcon(":/actions/save"));
    ui->actionExit->setIcon(QIcon(":/actions/exit"));
    ui->actionAboutQt->setIcon(QIcon(":/actions/about"));
    ui->actionAboutProgram->setIcon(QIcon(":/actions/about_program"));
    ui->actionPreferences->setIcon(QIcon(":/actions/preferences"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTitle()
{
    //Подставляем в название заголовка имя текущего открытого файла.
    //Комбинацией символов " [ * ] " обозначаем место, где будет выводиться знак "*" в случае,
    //когда содержимое окна модифицировано.
    QString lTitle = QString("TextEditor - %1 [*]").arg(mFileName);
    //устанавливаем заголовок окна
    setWindowTitle(lTitle);
}

bool MainWindow::askForFileSaveAndclose()
{
    if (isWindowModified()) //Если содержимое окна модифицировано
    {
        //вызываем диалог с вопросом, нужно ли сохранять изменения: подставляем в текст диалога
        //название текущего открытого файла, задаем кнопки: "Да", "Нет" и "Отмена".
        //Результат работы диалога (нажатой кнопки) записываем в переменную
        int lResult = QMessageBox::question(this, tr("Save changes"),
                                            QString(tr("File %1 is modified.Do you want to save your changes ?"))
                                                .arg(mFileName), QMessageBox::Yes, QMessageBox::No, QMessageBox::Cancel);

        if (QMessageBox::Yes == lResult) //Если нажали кнопку "Да"
        {
            slotSave(); //сохранить изменения
        }
        else
        {
            if (QMessageBox::Cancel == lResult) //Если нажали кнопку "Отменить"
            {
                return false;
            }
        }
    }
    return true;
}

void MainWindow::slotNew()
{
    mFileName = "Untitled File"; //Задать имя для нового файла по умолчанию
    ui->plainTextEdit->clear(); //Очистить текстовое поле
    setWindowModified(false); //Установить — содержание не модифицировано
    updateTitle(); //Обновить заголовок окна
}

void MainWindow::slotOpen()
{
//Вызвать системный диалог открытия файла в домашней папке пользователя
    QString lFileName = QFileDialog::getOpenFileName(this, "open file...", QDir::homePath(),
                                                 "Text files ( * .txt );; All files ( *.* ) ");
    //указываем фильтры для просмотра файлов
    if (lFileName.isEmpty()) //Если пользователь не выбрал ни одного файла
    {
        return; //выйти из метода
    }
    //Спросить пользователя о сохранении документа
    if (!askForFileSaveAndclose())
    {
    //Если пользователь нажал "Отмена" игнорировать вызов — продолжать работу
        return;
    }
    QFile lFile(lFileName); //Устанавливаем имя открытого файла
    //Если текстовый файл открыт только для чтения...
    if (lFile.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        mFileName = lFileName; //задать имя файла
        //читаем все содержимое и устанавливаем текст для редактора
        ui->plainTextEdit->setPlainText(lFile.readAll());
        lFile.close(); //закрываем открытый файл
        //устанавливаем состояние окна — содержимое не модифицировано
        setWindowModified(false);
        //и обновляем заголовок окна для демонстрации названия текущего открытого файла
        updateTitle();
    }
    else
    {
        //Если при открытии файла возникла ошибка выводим диалоговое окно с сообщением,
        //содержащим имя файла, одну кнопку "Ок" и заголовок "Error"
        QMessageBox::warning(this,
                             "Error",
                             QString("Could not open File %1 for reading").arg(lFile.fileName()),
                             QMessageBox::Ok);
    }
}

void MainWindow::slotSave()
{
//Если содержимое не модифицировано...
    if (!isWindowModified()) //Если содержимое не модифицировано
    {
        return; //Выйти из метода — продолжить работу
    }
    //Вызвать системный диалог сохранения файла в домашней папке пользователя
    QString lFileName = QFileDialog::getSaveFileName(this,
                                                     tr("Save File..."),
                                                     QDir::homePath(),
                                                     tr("Text files ( *.txt );; All files (*.*)"));
    //Если пользователь не выбрал имя файла для сохранения...
    if ( lFileName.isEmpty())
    {
        return; // ... выйти из метода
    }
    QFile lFile(lFileName); //Устанавливаем имя открытого файла
    //Если текстовый файл открыт для записи
    if ( lFile.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        mFileName = lFileName; //Задать имя файла
        //Создаем временный QByteArray для записи данных
        QByteArray lData;
        //Читаем текст из редактора и добавляем QByteArray, записываем в файл
        //и закрываем файл после записи
        lData.append(ui->plainTextEdit->toPlainText().toUtf8());
        lFile.write(lData);
        lFile.close();
        //Устанавливаем состояние окна — содержимое не модифицировано
        setWindowModified(false);
    }
    else
    {
        //Если при открытии файла возникла ошибка выводим диалоговое окно с сообщением,
        //содержащим имя файла, одну кнопку "Ок" и заголовок "Error"
        QMessageBox::warning(this, "Error", QString("Could not open File %1 for writing").arg(lFile.fileName()), QMessageBox::Ok);
    }
}

void MainWindow::slotAboutProgram()
{
    //Выводим диалоговое информационное окно с сообщением, куда подставляем версию и название
    //программы возвращаемых QApplication. Указываем — окно содержит заголовок "About".
    QMessageBox::about(this, tr("About"), QString("%1 v.%2").arg(qApp->applicationName(), qApp->applicationVersion()));

}

void MainWindow::showPreferencesDialog()
{
    mSettingsDialog->show();
}
