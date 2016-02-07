/*
 * objecttypeseditor.h
 * Copyright 2016, Thorbjørn Lindeijer <bjorn@lindeijer.nl>>
 *
 * This file is part of Tiled.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TILED_INTERNAL_OBJECTTYPESEDITOR_H
#define TILED_INTERNAL_OBJECTTYPESEDITOR_H

#include "properties.h"

#include <QMainWindow>

namespace Ui {
class ObjectTypesEditor;
}

class QtBrowserItem;
class QtGroupPropertyManager;
class QtProperty;
class QtVariantProperty;
class QtVariantPropertyManager;

namespace Tiled {
namespace Internal {

class ObjectTypesModel;

class ObjectTypesEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit ObjectTypesEditor(QWidget *parent = nullptr);
    ~ObjectTypesEditor();

signals:
    void closed();

protected:
    void closeEvent(QCloseEvent *) override;
    void changeEvent(QEvent *e) override;

private slots:
    void addObjectType();
    void selectedObjectTypesChanged();
    void removeSelectedObjectTypes();
    void objectTypeIndexClicked(const QModelIndex &index);
    void applyObjectTypes();
    void applyProperties();

    void chooseObjectTypesFile();
    void importObjectTypes();
    void exportObjectTypes();

    void updateProperties();
    void propertyValueChanged(QtProperty *property, const QVariant &val);

    void addProperty();
    void addProperty(const QString &name, const QString &value = QString());
    void editCustomProperty(const QString &name);
    void removeProperty();
    void renameProperty();
    void renameProperty(const QString &name);

    void currentItemChanged(QtBrowserItem *item);

private:
    QtVariantProperty *createProperty(int type,
                                      const QString &name);

    Ui::ObjectTypesEditor *mUi;
    ObjectTypesModel *mObjectTypesModel;

    QtVariantPropertyManager *mVariantManager;
    QtGroupPropertyManager *mGroupManager;
    QHash<QString, QtVariantProperty *> mNameToProperty;

    Properties mProperties;
    bool mUpdating;
};

} // namespace Internal
} // namespace Tiled

#endif // TILED_INTERNAL_OBJECTTYPESEDITOR_H
