/*************************************************************************

bq Cervantes e-book reader application
Copyright (C) 2011-2013  Mundoreader, S.L

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with the source code.  If not, see <http://www.gnu.org/licenses/>.

*************************************************************************/

#ifndef VIEWERPAGEHANDLERLANDSCAPE_H
#define VIEWERPAGEHANDLERLANDSCAPE_H

#include "ui_ViewerPageHandlerLandscape.h"
#include "MouseFilter.h"

class ViewerPageHandlerLandscape : public QWidget,
                                   protected Ui::ViewerPageHandlerLandscape
{
    Q_OBJECT

public:
    ViewerPageHandlerLandscape(QWidget*);
    virtual ~ViewerPageHandlerLandscape();


    bool                                shouldBeShown                       ();
    void                                hideBackBtn                         ();
    void                                showBackBtn                         ();
    void                                hideTitle                           ();
    void                                showTitle                           ();
    void                                hideDateTime                        ();
    void                                showDateTime                        ();
    void                                setCurrentReadingPercent            (int value);
    void                                hideChapterInfo                     ();

    void                                setPdfToolbarState                  (bool shouldBeShown){m_pdfToolbarShowed = shouldBeShown;}
    void                                setCurrentPageMode                  (bool isPdf);
    void                                updateBookTitle                     (const QString& title);
    void                                updateDateTime                      (const QString& dateTime);
    bool                                dateTimeisVisible                   ();

    virtual void                        updateDisplay                       ();
    void                                setChapterPos                       (const QList<int> chaptersPage);
    void                                setNeedToPaint                      (bool value) { b_needToRepaint = value; }

public slots:
    void                                handlePageChange                    (int, int, int);
    void                                resetPager                          ();
    void                                setChapterPage                      (int);

signals:
    void                                goBack                              ();
    void                                pdfMenuBtnClicked                   ();
    void                                pressEvent                          (TouchEvent*);

protected:
    void                                updatePageHandler                   ();
    void                                hideChapterLines                    ();
    virtual void                        showEvent                           (QShowEvent*);

    int                                 m_currentPageIni;
    int                                 m_currentPageEnd;
    int                                 m_totalPages;
    int                                 m_chapterLineWidth;
    bool                                m_pdfToolbarShowed;
    int                                 m_visibleMask; // Indicates which info can be shown.
    bool                                b_needToRepaint;
    QList<int>                          linesPos;

    enum EViewerPageHandlerMask
    {
        EVPHM_NONE          =   0,

        EVPHM_PROGRESSBAR   =   (1u << 1),
        EVPHM_PAGE          =   (1u << 2),
        EVPHM_BACK_BTN      =   (1u << 3),
        EVPHM_PDF           =   (1u << 4),
        EVPHM_CLOSE_BTN     =   (1u << 5),
        EVPHM_PROGRESS      =   (1u << 6),
        EVPHM_CHAPTER       =   (1u << 7),
        EVPHM_BOOK_TITLE    =   (1u << 8),
        EVPHM_DATE_TIME     =   (1u << 9),
        EVPHM_CHAPTERLINE   =   (1u << 10)
    };
};

#endif // VIEWERPAGEHANDLERLANDSCAPE_H
