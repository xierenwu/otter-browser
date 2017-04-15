/**************************************************************************
* Otter Browser: Web browser controlled by the user, not vice-versa.
* Copyright (C) 2015 - 2017 Michal Dutkiewicz aka Emdek <michal@emdek.pl>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*
**************************************************************************/

#ifndef OTTER_NOTESCONTENTSWIDGET_H
#define OTTER_NOTESCONTENTSWIDGET_H

#include "../../../core/NotesManager.h"
#include "../../../ui/ContentsWidget.h"

#include <QtGui/QStandardItemModel>

namespace Otter
{

namespace Ui
{
	class NotesContentsWidget;
}

class Window;

class NotesContentsWidget : public ContentsWidget
{
	Q_OBJECT

public:
	explicit NotesContentsWidget(const QVariantMap &parameters, Window *window);
	~NotesContentsWidget();

	void print(QPrinter *printer) override;
	Action* createAction(int identifier, const QVariantMap parameters = QVariantMap(), bool followState = true) override;
	QString getTitle() const override;
	QLatin1String getType() const override;
	QUrl getUrl() const override;
	QIcon getIcon() const override;
	bool eventFilter(QObject *object, QEvent *event) override;

public slots:
	void triggerAction(int identifier, const QVariantMap &parameters = QVariantMap()) override;

protected:
	void changeEvent(QEvent *event) override;
	BookmarksItem* findFolder(const QModelIndex &index);

protected slots:
	void addNote();
	void addFolder();
	void addSeparator();
	void removeNote();
	void restoreNote();
	void openUrl(const QModelIndex &index = QModelIndex());
	void showContextMenu(const QPoint &position);
	void updateActions(bool updateText = true);
	void updateText();

private:
	QHash<int, Action*> m_actions;
	Ui::NotesContentsWidget *m_ui;
};

}

#endif
