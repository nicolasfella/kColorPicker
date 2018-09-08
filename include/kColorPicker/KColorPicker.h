/*
 * Copyright (C) 2018 Damir Porobic <damir.porobic@gmx.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef KCOLORPICKER_KCOLORPICKER_H
#define KCOLORPICKER_KCOLORPICKER_H

#include <QToolButton>
#include <QColor>
#include <QList>

#include <kColorPicker/KColorPickerExport.h>

class KCOLORPICKER_EXPORT KColorPicker : public QToolButton
{
Q_OBJECT
public:
    KColorPicker();
    KColorPicker(KColorPicker &&other) = default;
    ~KColorPicker();
    KColorPicker &operator=(KColorPicker &&other) = default;
    void setFixedSize(const QSize& size);
    void setFixedSize(int width, int height);

signals:
    void colorChanged(const QColor &color) const;

public slots:
    void setColor(const QColor &color);

private:
    class Impl;
    QSharedDataPointer<Impl> mImpl;

    void addDefaultColors();
    void setColorIcon(const QColor& color);
    void setColorIconWithSize(const QColor& color, const QSize &size);

private slots:
    void colorSelected(const QColor &color);
};

#endif //KCOLORPICKER_KCOLORPICKER_H
