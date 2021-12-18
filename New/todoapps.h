#pragma once

#include <QtWidgets/QWidget>
#include "ui_ToDoApps.h"
#include <QDate>
#include <QDir>
#include <QWidget>
#include <QDateTime>
#include <QScrollArea>
#include <QListWidget>
#include <QWidgetAction>
#include <QCalendarWidget>

#include <QLabel>
#include <QAction>
#include <QLineEdit>
#include <QDateEdit>
#include <QToolButton>
#include <QPushButton>

#include <QDebug>
#include <QBuffer>
#include <QLocale>

#include <QCheckBox>
#include <QComboBox>
#include <QGroupBox>
#include <QMessageBox>
#include <QGridLayout>

#include <QDomDocument>
#include <QtXml/QDomNode>
#include <QTextCharFormat>
#include <QtXml/QDomNodeList>

#include "networkmanager.h"
#include "event.h"

class ToDoApps : public QWidget
{
    Q_OBJECT

public:
    ToDoApps(QString username, QString password, QWidget *parent = Q_NULLPTR);

private:
    Ui::ToDoAppsClass ui;

    //NETWORK MANAGER
    QNetworkAccessManager* manager;
    QNetworkReply* putReply;
    QNetworkReply* deleteReply;

    //evento da inserire
    Event *eventToPut;

    //evento grafico da cancellare
    QFrame* eventToDelete;

    //uid dell'evento da cancellare
    QString uidToDelete;

    QString username;
    QString password;

    std::vector<Event>* events;

public:
    void initStylesheet();
    void createNewTask(QString uid, QString taskName, QString date, QString location, QString dtstart, QString dtend);
    void showCurrentEvents();

public slots:
    void SlotAddNewTask();
    void SlotDeleteTask();
    void addEventRequest(QString taskName, QString date, QString location, QTime dtstart, QTime dtend);
    void addEventRequestFinished();
    void removeEventRequest(QString uid);
    void removeEventRequestFinished();
    void handleError();
    void getCalendar();

signals:
    void SignalAddNewTask(QString taskName, QString date); // incase you wonder how to create custom signal. Useful when you want to call this signal in other classes/widgets

private slots:
    void on_calendarWidget_clicked(const QDate &date);
    void on_AddNewBtn_clicked();
    void on_DeleteTask_clicked();
};
