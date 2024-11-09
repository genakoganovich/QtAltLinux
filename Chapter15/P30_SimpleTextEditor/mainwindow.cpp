#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settingsdialog.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QSettings>
#include <QTextCursor>

const QString MainWindow::SETTINGS_GROUP_VIEW = "ViewSettings";
const QString MainWindow::SETTING_SHOW_TOOLBAR = "SettingsShowToolBar";
const QString MainWindow::SETTING_SHOW_STATUS_BAR = "SettingsShowStatusBar";
const QString MainWindow::SETTING_SAVE_GEOMETRY = "SettingsSaveGeometry";
const QString MainWindow::SETTING_GEOMETRY = "SettingsGeometry";

const int MainWindow::TIME_OUT = 1000;

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
    connect(mSettingsDialog, SIGNAL(accepted()), this, SLOT(slotPreferencesAccepted()), Qt::UniqueConnection);
    connect(ui->plainTextEdit, SIGNAL(cursorPositionChanged()), this, SLOT(slotStatusBarMessage()), Qt::UniqueConnection);

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

    // Восстановите геометрию при запуске
    restoreGeometrySettings();
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

void MainWindow::readSettings()
{
    //Указываем, где хранились настройки. QSettings::NativeFormat — в формате определенном системой
    //QSettings::UserScope — настройки для каждого пользователя отдельно.
    //Также устанавливаем имя организации и название программы
    QSettings lsettings(QSettings::NativeFormat, QSettings::UserScope, " ", qApp->applicationName());
    //Открываем группу настроек
    lsettings.beginGroup(SETTINGS_GROUP_VIEW);
    //Читаем настройки
    bool lShowToolBar = lsettings.value(SETTING_SHOW_TOOLBAR, true).toBool();
    mSettingsDialog->setShowToolBar(lShowToolBar);
    bool lShowStatusBar = lsettings.value(SETTING_SHOW_STATUS_BAR, true).toBool();
    mSettingsDialog->setShowStatusBar(lShowStatusBar);
    bool lSaveGeometry = lsettings.value(SETTING_SAVE_GEOMETRY, true).toBool();
    mSettingsDialog->setSaveGeometry(lSaveGeometry);
}

void MainWindow::writeSettings()
{
    //Указываем как сохранять настройки. QSettings::NativeFormat — в формате определенном системой
    //QSettings::UserScope — настройки для каждого пользователя отдельно.
    //Также устанавливаем имя организации и название программы.
    QSettings lSettings(QSettings::NativeFormat, QSettings::UserScope, " ", qApp->applicationName());
    //Открываем группу настроек
    lSettings.beginGroup(SETTINGS_GROUP_VIEW);
    //Записываем настройки
    lSettings.setValue(SETTING_SHOW_TOOLBAR, mSettingsDialog->isShowToolBar());
    lSettings.setValue(SETTING_SHOW_STATUS_BAR, mSettingsDialog->isShowStatusBar());
    lSettings.setValue(SETTING_SAVE_GEOMETRY, mSettingsDialog->isSaveGeometry());
}

void MainWindow::applySettings()
{
    //Читаем настройки установленые в диалоге и применяем их
    ui->toolBar->setVisible(mSettingsDialog->isShowToolBar());
    ui->statusBar->setVisible(mSettingsDialog->isShowStatusBar());
}

void MainWindow::restoreGeometrySettings()
{
    QSettings lSettings(QSettings::NativeFormat, QSettings::UserScope, " ", qApp->applicationName());
    //Открываем группу настроек
    lSettings.beginGroup(SETTINGS_GROUP_VIEW);
    if(lSettings.value(SETTING_SAVE_GEOMETRY, true).toBool())
    {
        restoreGeometry(lSettings.value(SETTING_GEOMETRY).toByteArray());
    }
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
    readSettings(); //Считываем настройки и устанавливаем их для диалога
    mSettingsDialog->show(); //Показываем диалог настроек
}

void MainWindow::slotPreferencesAccepted()
{
    writeSettings(); //Записать новые настройки
    applySettings(); //Применить настройки
}

void MainWindow::slotStatusBarMessage()
{
    // Получаем текущую позицию курсора
    QTextCursor cursor = ui->plainTextEdit->textCursor();
    int line = cursor.blockNumber() + 1;       // Номер строки (начиная с 1)
    int column = cursor.columnNumber() + 1;    // Номер столбца (начиная с 1)

    // Обновляем текст метки
    ui->statusBar->showMessage(QString("Позиция курсора: (%1, %2)").arg(line).arg(column), TIME_OUT);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QSettings lSettings(QSettings::NativeFormat, QSettings::UserScope, " ", qApp->applicationName());
    //Открываем группу настроек
    lSettings.beginGroup(SETTINGS_GROUP_VIEW);
    if(lSettings.value(SETTING_SAVE_GEOMETRY, true).toBool())
    {
        lSettings.setValue(SETTING_GEOMETRY, saveGeometry());
    }
    QMainWindow::closeEvent(event);
}
