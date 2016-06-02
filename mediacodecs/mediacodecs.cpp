#include <QDebug>
#include <QDir>
#include <QUrl>
#include <QStandardPaths>
#include "mediacodecs.h"

MediaCodecs::MediaCodecs(QObject *parent) : QObject(parent)
{
    m_audioRecorder = new QAudioRecorder( this );
}

void MediaCodecs::setCameraObject(QObject *cam)
{
    // get the QCamera from the declarative camera's mediaObject property.
    m_camera = qvariant_cast<QCamera*>(cam->property("mediaObject"));
    m_mediaRecorder = new QMediaRecorder(m_camera, this);
    m_mediaRecorder->setOutputLocation( QUrl(getFilePath("sample.mp4")));
}


QObject *MediaCodecs::cameraObject() const
{
    return m_camera;
}

QStringList MediaCodecs::supportedAudioCodecs() {
    return m_audioRecorder->supportedAudioCodecs();
}

QStringList MediaCodecs::supportedContainers() {
    return m_audioRecorder->supportedContainers();
}

QStringList MediaCodecs::availableMetaData() {
    // qDebug() << "availableMetaData" << m_mediaRecorder->availableMetaData();
    return m_mediaRecorder->availableMetaData();
    return QStringList();
}

QString MediaCodecs::getFilePath(const QString filename) const
{
    QString writablePath = QStandardPaths::
            writableLocation(QStandardPaths::DataLocation);
    qDebug() << "writablePath: " << writablePath;

    QString absolutePath = QDir(writablePath).absolutePath();
    qDebug() << "absoluePath: " << absolutePath;

    // We need to make sure we have the path for storage
    QDir dir(absolutePath);
    if ( dir.mkdir(absolutePath) ) {
        qDebug() << "Successfully created the path!";
    }

    QString path = absolutePath + "/" + filename;

    qDebug() << "path: " << path;

    return path;
}

