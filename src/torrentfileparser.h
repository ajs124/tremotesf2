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

#include <QObject>
#include <QVariantList>
#include <QVariantMap>

class QThread;

namespace tremotesf
{
    class TorrentFileParser : public QObject
    {
        Q_OBJECT
        Q_ENUMS(Error)
        Q_PROPERTY(QString filePath READ filePath WRITE setFilePath)
        Q_PROPERTY(bool loaded READ isLoaded NOTIFY done)
        Q_PROPERTY(Error error READ error NOTIFY done)
        Q_PROPERTY(QString errorString READ errorString NOTIFY done)
        Q_PROPERTY(QByteArray fileData READ fileData)
    public:
        enum Error
        {
            NoError,
            WrongMimeType,
            ReadingError,
            ParsingError
        };

        explicit TorrentFileParser(const QString& filePath = QString(), QObject* parent = nullptr);
        ~TorrentFileParser();

        const QString& filePath() const;
        void setFilePath(const QString& path);

        bool isLoaded() const;
        Error error() const;
        QString errorString() const;
        const QByteArray& fileData() const;
        const QVariantMap& parseResult() const;

    private:
        QThread* mWorkerThread;

        QString mFilePath;
        Error mError;
        bool mLoaded;

        QByteArray mFileData;
        QVariantMap mParseResult;
    signals:
        void requestParse(const QString& filePath);
        void done();
    };
}
