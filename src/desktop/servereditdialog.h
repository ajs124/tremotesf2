/*
 * Tremotesf
 * Copyright (C) 2015-2017 Alexey Rochev <equeim@gmail.com>
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

#ifndef TREMOTESF_SERVEREDITDIALOG_H
#define TREMOTESF_SERVEREDITDIALOG_H

#include <QDialog>

class QCheckBox;
class QDialogButtonBox;
class QGroupBox;
class QLineEdit;
class QPlainTextEdit;
class QSpinBox;

namespace tremotesf
{
    class ServersModel;

    class ServerEditDialog : public QDialog
    {
    public:
        explicit ServerEditDialog(ServersModel* serversModel, int row, QWidget* parent = nullptr);
        QSize sizeHint() const override;
        void accept() override;

    private:
        void setupUi();
        void canAcceptUpdate();
        void setServer();

    private:
        ServersModel* mServersModel;
        QString mServerName;

        QLineEdit* mNameLineEdit;
        QLineEdit* mAddressLineEdit;
        QSpinBox* mPortSpinBox;
        QLineEdit* mApiPathLineEdit;
        QGroupBox* mHttpsGroupBox;
        QCheckBox* mSelfSignedCertificateCheckBox;
        QPlainTextEdit* mSelfSignedCertificateEdit;
        QCheckBox* mClientCertificateCheckBox;
        QPlainTextEdit* mClientCertificateEdit;
        QGroupBox* mAuthenticationGroupBox;
        QLineEdit* mUsernameLineEdit;
        QLineEdit* mPasswordLineEdit;
        QSpinBox* mUpdateIntervalSpinBox;
        QSpinBox* mTimeoutSpinBox;

        QDialogButtonBox* mDialogButtonBox;
    };
}

#endif // TREMOTESF_SERVEREDITDIALOG_H
