#ifndef MEDIACODECS_H
#define MEDIACODECS_H

#include <QAudioRecorder>
#include <QMediaRecorder>
#include <QCamera>
#include <QObject>

class MediaCodecs : public QObject
{
    Q_OBJECT
      Q_PROPERTY(QObject* cameraObject READ cameraObject WRITE setCameraObject)
public:
    explicit MediaCodecs(QObject *parent = 0);
    QObject* cameraObject() const;
    void setCameraObject(QObject *cam);

    Q_INVOKABLE QStringList supportedAudioCodecs();
    Q_INVOKABLE QStringList supportedContainers();
    Q_INVOKABLE QStringList availableMetaData();

private:
    QString getFilePath(const QString filename) const;

signals:

public slots:

private:
    QAudioRecorder *m_audioRecorder;
    QMediaRecorder *m_mediaRecorder;
    QCamera *m_camera;
};

#endif // MEDIACODECS_H
