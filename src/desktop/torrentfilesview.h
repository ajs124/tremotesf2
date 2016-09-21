/*
 * Tremotesf
 * Copyright (C) 2015-2016 Alexey Rochev <equeim@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TREMOTESF_TORRENTFILESVIEW_H
#define TREMOTESF_TORRENTFILESVIEW_H

#include "basetreeview.h"

namespace tremotesf
{
    class BaseTorrentFilesModel;
    class LocalTorrentFilesModel;
    class Torrent;
    class TorrentFilesProxyModel;

    class TorrentFilesView : public BaseTreeView
    {
    public:
        explicit TorrentFilesView(LocalTorrentFilesModel* model, QWidget* parent = nullptr);
        explicit TorrentFilesView(Torrent* torrent, QWidget* parent = nullptr);
        ~TorrentFilesView();
    private:
        void init();
        void showContextMenu(const QPoint& pos);
    private:
        bool mLocalFile;
        BaseTorrentFilesModel* mModel;
        TorrentFilesProxyModel* mProxyModel;
    };
}

#endif // TREMOTESF_TORRENTFILESVIEW_H