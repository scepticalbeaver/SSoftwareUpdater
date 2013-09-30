#pragma once

#include <QtCore/QCoreApplication>
#include <QtCore/QStringList>
#include <QtCore/QSettings>
#include <QtCore/QFileInfo>
#include <QtCore/QProcess>
#include <QtCore/QTimer>
#include <QDebug>

#include "downloader.h"
#include "xmlDataParser.h"
#include "updateManager.h"
#include "communicator.h"

class UpdateProcessor : public QObject
{
	Q_OBJECT
public:
	UpdateProcessor();
	~UpdateProcessor();

	void startUpdateControl();

public slots:
	void startUpdatingProcess();

protected:
	void initConnections();
	//! \brief parseParams
	//! \return True if arguments are correct, false otherwise
	bool parseParams();
	//! \brief hasNewUpdates
	//! \param newVersion
	//! \return True if new version is newer than current
	bool hasNewUpdates(QString const newVersion);
	void startSetupProcess(Update *update);
	void checkoutPreparedUpdates();
	void restartMainApplication();

	static int const retryTimerout = 1 * 15 * 1000; //                 ! ////////////////
	static int const maxAttemptsCount = 3;
	int mCurAttempt;
	bool mHardUpdate;
	QString mUpdatesFolder;
	QTimer mRetryTimer;
	QMap<QString, QString> mParams;
	Communicator *mCommunicator;
	Downloader *mDownloader;
	DetailsParser *mParser;
	UpdateManager *mUpdateInfo;

protected slots:
	void detailsChanged();
	void fileReady(QString const filePath);
	void updateFinished(bool hasSuccess);
	void downloadErrors(QString error = QString());
	void jobDoneQuit();
};

