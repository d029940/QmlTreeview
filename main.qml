import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Basic
import QtQuick.Layouts

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    TreeView {
        id: treeView

        anchors.fill: parent

        delegate: TreeViewDelegate {
            id: treeDelegate
            text: model.display
            onClicked: {

                var mi = treeDelegate.treeView.index(row, column)
                console.log("model.index =", mi)
                treeView.model.showQModelIndex(mi)
            }
        }
        model: _model
    }
}
