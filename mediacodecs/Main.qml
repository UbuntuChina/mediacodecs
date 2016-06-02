import QtQuick 2.4
import Ubuntu.Components 1.3
import MediaCodecs 1.0
import QtMultimedia 5.0

MainView {
    // objectName for functional testing purposes (autopilot-qt5)
    objectName: "mainView"

    // Note! applicationName needs to match the "name" field of the click manifest
    applicationName: "mediacodecs.xiaoguo"

    width: units.gu(60)
    height: units.gu(85)

    MediaCodecs {
        id: codecs
        cameraObject: camera
    }

    Page {
        id: page
        header: PageHeader {
            id: pageHeader
            title: i18n.tr("Media codecs")
            StyleHints {
                foregroundColor: UbuntuColors.orange
                backgroundColor: UbuntuColors.porcelain
                dividerColor: UbuntuColors.slate
            }
        }

        Camera {
            id: camera

            imageProcessing.whiteBalanceMode: CameraImageProcessing.WhiteBalanceFlash

            flash.mode: Camera.FlashRedEyeReduction

            imageCapture {
                onImageCaptured: {
                    photoPreview.source = preview  // Show the preview in an Image
                }
            }
        }

        Column {
            anchors {
                left: parent.left
                right: parent.right
                bottom: parent.bottom
                top: page.header.bottom
            }

            spacing: units.gu(1)

            Label {
                text: "<b>Supported Audio codecs:</b>"
            }

            ListView {
                width: parent.width
                height: units.gu(10)
                model:codecs.supportedAudioCodecs()
                delegate: Text {
                    text: modelData
                }
            }

            Rectangle {
                width: parent.width
                height: units.gu(0.1)
            }

            Label {
                text: "<b>Supported Audio Containers:</b>"
            }

            ListView {
                width: parent.width
                height: units.gu(15)
                model:codecs.supportedContainers()
                delegate: Text {
                    text: modelData
                }
            }

//            Label {
//                text: "<b>Supported meta data:</b>"
//            }

//            ListView {
//                width: parent.width
//                height: units.gu(15)
//                model:codecs.availableMetaData()
//                delegate: Text {
//                    text: modelData
//                }
//            }
        }
    }
}

