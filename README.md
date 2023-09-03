# QmlTreeview
Example for QMLTree QModelIndex to C++

This is an example on how to use QModelIndex in a Treeview exchanging data from C++ to QML and back.

It uses quite an easy tree model, which is published to QML.
The purpose ist to send back the information of the clicked item to C++.

There are qDebug statements showing the address, content and parent of each treeItem.
On clicking a treeItem in the TreeView QML calls a c++ func `void TreeModel::showQModelIndex(const QModelIndex &index) const` 
which prints the chosen TreeItem via `qDebug()` in the console.

There are two main QML files:
- main.qml which uses the Qt TreeviewDelagate
- mainOwnDelegate which creates its own TreeviewDelegate

The chosen TreeviewDelegate can be swapped in the main.cpp.


