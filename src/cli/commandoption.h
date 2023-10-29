// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2017-2019 Alejandro Sirgo Rica & Contributors
#pragma once

#include <QStringList>
#include <functional>

using std::function;

// Class representing a command-line option
class CommandOption
{
public:
    // Constructors for creating a CommandOption
    CommandOption(const QString& name,
                  QString description,
                  QString valueName = QString(),
                  QString defaultValue = QString());

    CommandOption(QStringList names,
                  QString description,
                  QString valueName = QString(),
                  QString defaultValue = QString());

    void setName(const QString& name);
    void setNames(const QStringList& names);
    QStringList names() const;
    QStringList dashedNames() const;

    void setValueName(const QString& name);
    QString valueName() const;

    void setValue(const QString& value);
    QString value() const;

    void addChecker(const function<bool(QString const&)> checker,
                    const QString& errMsg);
    bool checkValue(const QString& value) const;

    QString description() const;
    void setDescription(const QString& description);

    QString errorMsg() const;

    bool operator==(const CommandOption& option) const;

private:
    QStringList m_names;        // Names for the option
    QString m_description;      // Description of the option
    QString m_valueName;       // Name of the option's value
    QString m_value;           // The actual value

    function<bool(QString const&)> m_checker; // Value checker function
    QString m_errorMsg;        // Error message for value checks
};
