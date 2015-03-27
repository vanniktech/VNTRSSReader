/*
    Copyright 2014-2015 Vanniktech - Niklas Baudy

    This file is part of VNTRSSReader.

    VNTRSSReader is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    VNTRSSReader is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with VNTRSSReader. If not, see <http://www.gnu.org/licenses/>.
*/

#include <QtTest/QtTest>
#include <QSignalSpy>

#include "../VNTRSSReader/vntrssreader.h"

static const QUrl LINK = QUrl("http://vanniktech.de");
static const QString TITLE = "Vanniktech";
static const QString CHANNEL_DESCRIPTION = "Lorem ipsum dolor sit amet, consectetur adipisicing elit. Tempore quo quos aut, ducimus quaerat quae inventore odio saepe facilis, accusantium minima numquam necessitatibus eius quidem, est reiciendis ratione vero blanditiis!";
static const QUrl IMAGE = QUrl("http://vanniktech.de/img/nav/speedreader.png");
static const QString IMAGE_FILE_TYPE = "png";
static const QString LANGUAGE = "en";
static const QString ITEM_DESCRIPTION = "Lorem ipsum dolor sit amet, consectetur adipisicing elit. Quas sed praesentium iste, atque dicta molestiae sunt voluptate nostrum voluptatibus consequatur nihil, ad itaque dolorem, perferendis nulla consequuntur sit. Mollitia, sunt.";
static const QString ITEM_DESCRIPTION_PLAIN = "Lorem ipsum dolor sit amet, consectetur adipisicing elit. Tempore quo quos aut, ducimus quaerat quae inventore odio saepe facilis, accusantium minima numquam necessitatibus eius quidem, est reiciendis ratione vero blanditiis!";
static const QString PLAIN_TITLE = "Vanniktech Vanniktech";

class UnitTests: public QObject
{
    Q_OBJECT
private slots:
    void testAtomSiteBarDate();
    void testAtomSiteBarLink();
    void testAtomSiteBarImageInternet();
    void testAtomSiteBarLanguage();
    void testAtomSiteBarTitle();
    void testAtomSiteBarDescription();
    void testAtomSiteBarItemSize();
    void testAtomSiteBarItemLink();
    void testAtomSiteBarItemDate();
    void testAtomSiteBarItemTitle();
    void testAtomSiteBarItemDescription();

    void testAtomSiteExampleDate();
    void testAtomSiteExampleLink();
    void testAtomSiteExampleImageInternet();
    void testAtomSiteExampleLanguage();
    void testAtomSiteExampleTitle();
    void testAtomSiteExampleDescription();
    void testAtomSiteExampleItemSize();
    void testAtomSiteExampleItemLink();
    void testAtomSiteExampleItemDate();
    void testAtomSiteExampleItemTitle();
    void testAtomSiteExampleItemDescription();

    void testAtomSiteFooDate();
    void testAtomSiteFooLink();
    void testAtomSiteFooImageInternet();
    void testAtomSiteFooLanguage();
    void testAtomSiteFooTitle();
    void testAtomSiteFooDescription();
    void testAtomSiteFooItemSize();
    void testAtomSiteFooItemLink();
    void testAtomSiteFooItemImages();
    void testAtomSiteFooItemDate();
    void testAtomSiteFooItemTitle();
    void testAtomSiteFooItemDescription();

    void testRSSSiteBarDate();
    void testRSSSiteBarLink();
    void testRSSSiteBarImageInternet();
    void testRSSSiteBarLanguage();
    void testRSSSiteBarTitle();
    void testRSSSiteBarDescription();
    void testRSSSiteBarItemSize();
    void testRSSSiteBarItemLink();
    void testRSSSiteBarItemDate();
    void testRSSSiteBarItemTitle();
    void testRSSSiteBarItemImageInternet();
    void testRSSSiteBarItemPlainDescription();

    void testRSSSiteExampleDate();
    void testRSSSiteExampleLink();
    void testRSSSiteExampleImageInternet();
    void testRSSSiteExampleLanguage();
    void testRSSSiteExampleTitle();
    void testRSSSiteExampleDescription();
    void testRSSSiteExampleItemSize();
    void testRSSSiteExampleItemLink();
    void testRSSSiteExampleItemDate();
    void testRSSSiteExampleItemTitle();
    void testRSSSiteExampleItemImage();
    void testRSSSiteExampleItemDescription();

    void testRSSSiteFooDate();
    void testRSSSiteFooLink();
    void testRSSSiteFooImageInternet();
    void testRSSSiteFooLanguage();
    void testRSSSiteFooTitle();
    void testRSSSiteFooDescription();
    void testRSSSiteFooItemSize();
    void testRSSSiteFooItemLink();
    void testRSSSiteFooItemDate();
    void testRSSSiteFooItemTitle();
    void testRSSSiteFooItemImage();
    void testRSSSiteFooItemDescription();

    void testAtomChannelDateSet();
    void testRSSChannelDateSet();
    void testAtomChannelDateEmpty();
    void testRSSChannelDateEmpty();
    void testAtomChannelDateNull();
    void testRSSChannelDateNull();

    void testAtomChannelLinkNull();
    void testRSSChannelLinkNull();
    void testAtomChannelLinkSet();
    void testAtomChannelLinkTwiceSet();
    void testRSSChannelLinkSet();
    void testAtomChannelLinkEmpty();
    void testRSSChannelLinkEmpty();

    void testAtomChannelTitleNull();
    void testRSSChannelTitleNull();
    void testAtomChannelTitlePlainSet();
    void testRSSChannelTitlePlainSet();
    void testAtomChannelTitleSet();
    void testRSSChannelTitleSet();
    void testAtomChannelTitleEmpty();
    void testRSSChannelTitleEmpty();

    void testAtomChannelDescriptionNull();
    void testRSSChannelDescriptionNull();
    void testAtomChannelDescriptionSet();
    void testRSSChannelDescriptionSet();
    void testAtomChannelDescriptionPlainSet();
    void testRSSChannelDescriptionPlainSet();
    void testAtomChannelDescriptionEmpty();
    void testRSSChannelDescriptionEmpty();

    void testAtomChannelImageNull();
    void testRSSChannelImageNull();
    void testAtomChannelImageSet();
    void testRSSChannelImageSet();
    void testAtomChannelImageEmpty();
    void testRSSChannelImageEmpty();

    void testAtomChannelLanguageSet();
    void testRSSChannelLanguageSet();
    void testAtomChannelLanguageEmpty();
    void testRSSChannelLanguageEmpty();
    void testAtomChannelLanguageNull();
    void testRSSChannelLanguageNull();

    void testAtomChannelItemSet();
    void testRSSChannelItemSet();
    void testAtomChannelItemEmpty();
    void testRSSChannelItemEmpty();
    void testAtomChannelItemNull();
    void testRSSChannelItemNull();

    void testAtomItemDateSet();
    void testRSSItemDateSet();
    void testAtomItemDateEmpty();
    void testRSSItemDateEmpty();
    void testAtomItemDateNull();
    void testRSSItemDateNull();

    void testAtomItemLinkSet();
    void testRSSItemLinkSet();
    void testAtomItemLinkEmpty();
    void testRSSItemLinkEmpty();
    void testAtomItemLinkNull();
    void testRSSItemLinkNull();

    void testAtomItemTitleSet();
    void testRSSItemTitleSet();
    void testAtomItemTitlePlainSet();
    void testRSSItemTitlePlainSet();
    void testAtomItemTitleEmpty();
    void testRSSItemTitleEmpty();
    void testAtomItemTitleNull();
    void testRSSItemTitleNull();

    void testAtomItemDescriptionSet();
    void testRSSItemDescriptionSet();
    void testAtomItemDescriptionPlainSet();
    void testRSSItemDescriptionPlainSet();
    void testAtomItemDescriptionEmpty();
    void testRSSItemDescriptionEmpty();
    void testAtomItemDescriptionNull();
    void testRSSItemDescriptionNull();

    void testAtomItemDescriptionImageSet();
    void testRSSItemDescriptionImageSet();
    void testAtomItemDescriptionImageEmpty();
    void testRSSItemDescriptionImageEmpty();
    void testAtomItemDescriptionImageNull();
    void testRSSItemDescriptionImageNull();

    void testAtomItemImageSet();
    void testRSSItemImageSet();
    void testAtomItemImageEmpty();
    void testRSSItemImageEmpty();
    void testAtomItemImageNull();

    void testRSSItemImageNull();
    void testRSSItemImageClutterSet();
    void testRSSItemImageClutterEmpty();
    void testRSSItemImageClutterNull();

    void testAtomItemImageJPEGSet();
    void testAtomItemImageJPEGNull();
    void testAtomItemImageJPEGEmpty();

    void testAtomItemImagePNGSet();
    void testAtomItemImagePNGNull();
    void testAtomItemImagePNGEmpty();

    void testVanniktechAtom();
    void testVanniktechAtomRedirect();
    void testVanniktechRSS();
    void testVanniktechRSSRedirect();

    void testVanniktechLiveEN();
    void testVanniktechLiveDE();

    void testInvalidFeed();
    void testInvalidXML();
    void testInvalidResonseEmpty();

private:
    VNTRSSChannel* getRSSChannel(const QUrl &url);
    VNTRSSChannel* getRSSChannel(const QString &fileName);
    VNTRSSItem* getFirstRSSItem(const QString &fileName);
    QDateTime getSimpleDateFormatAtom(const QString &date);
    QDateTime getSimpleDateFormatRSS(const QString &date);
};

void UnitTests::testAtomSiteBarDate() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("atom-site-bar.xml");
    QCOMPARE(rssChannel->getDate(), this->getSimpleDateFormatAtom("2014-11-1413:30:41"));
}

void UnitTests::testAtomSiteBarLink() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("atom-site-bar.xml");
    QCOMPARE(rssChannel->getLink(), QUrl("http://www.example.bar/"));
}

void UnitTests::testAtomSiteBarImageInternet() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("atom-site-bar.xml");
    QCOMPARE(rssChannel->getImageUrl(), QUrl("http://www.example.bar/rss/logo.png"));
    QCOMPARE(rssChannel->getImageFileType(), QString("png"));
}

void UnitTests::testAtomSiteBarLanguage() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("atom-site-bar.xml");
    QCOMPARE(rssChannel->getLanguage(), QString("en"));
}

void UnitTests::testAtomSiteBarTitle() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("atom-site-bar.xml");
    QCOMPARE(rssChannel->getTitle(), QString("Bar title"));
    QCOMPARE(rssChannel->getPlainTitle(), QString("Bar title"));
}

void UnitTests::testAtomSiteBarDescription() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("atom-site-bar.xml");
    QCOMPARE(rssChannel->getDescription(), QString("Bar description"));
    QCOMPARE(rssChannel->getPlainDescription(), QString("Bar description"));
}

void UnitTests::testAtomSiteBarItemSize() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("atom-site-bar.xml");
    QList<VNTRSSItem*> rssItems = rssChannel->getRSSItems();
    QCOMPARE(rssItems.size(), 50);
}

void UnitTests::testAtomSiteBarItemLink() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("atom-site-bar.xml");
    QString links[] = { "http://example.bar/atom/8c5f5a0a.html", "http://example.bar/atom/2fe9875f.html", "http://example.bar/atom/d0dfbf34.html", "http://example.bar/atom/23a424b1.html", "http://example.bar/atom/bf7d7f7f.html", "http://example.bar/atom/bf4ce65f.html", "http://example.bar/atom/f1e4fd80.html", "http://example.bar/atom/10f2a2b8.html", "http://example.bar/atom/68135db8.html", "http://example.bar/atom/795a82cd.html", "http://example.bar/atom/203ac23b.html", "http://example.bar/atom/fa99d17b.html", "http://example.bar/atom/f0f85b60.html", "http://example.bar/atom/8c0f2f5e.html", "http://example.bar/atom/3906e4f6.html", "http://example.bar/atom/971f5ce0.html", "http://example.bar/atom/e84581c6.html", "http://example.bar/atom/2f85af27.html", "http://example.bar/atom/8c2af45f.html", "http://example.bar/atom/5d7b4161.html", "http://example.bar/atom/302d50dc.html", "http://example.bar/atom/90208f8d.html", "http://example.bar/atom/c88a90c7.html", "http://example.bar/atom/ead08246.html", "http://example.bar/atom/e58a02d9.html", "http://example.bar/atom/5d6af025.html", "http://example.bar/atom/ebb0a81f.html", "http://example.bar/atom/8c87ec73.html", "http://example.bar/atom/782e33e5.html", "http://example.bar/atom/fb685a9b.html", "http://example.bar/atom/c1238ed0.html", "http://example.bar/atom/bdff113e.html", "http://example.bar/atom/d63401d6.html", "http://example.bar/atom/612f696d.html", "http://example.bar/atom/92157863.html", "http://example.bar/atom/4226d7f1.html", "http://example.bar/atom/bf9697d8.html", "http://example.bar/atom/28069aed.html", "http://example.bar/atom/91fde9e7.html", "http://example.bar/atom/e41be7b2.html", "http://example.bar/atom/4628b0df.html", "http://example.bar/atom/76a8d8a0.html", "http://example.bar/atom/d30e48b0.html", "http://example.bar/atom/e310c694.html", "http://example.bar/atom/bd862e70.html", "http://example.bar/atom/9bdbf04f.html", "http://example.bar/atom/2e491b50.html", "http://example.bar/atom/4fbf5508.html", "http://example.bar/atom/d231b851.html", "http://example.bar/atom/a4f77253.html" };
    int index = 0;

    foreach (VNTRSSItem* rssItem, rssChannel->getRSSItems()) {
        QCOMPARE(rssItem->getLink(), QUrl(links[index++]));
    }
}

void UnitTests::testAtomSiteBarItemDate() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("atom-site-bar.xml");
    QString dates[] = { "2014-11-1413:28:04", "2014-11-1412:29:31", "2014-11-1411:21:04", "2014-11-1410:31:07", "2014-11-1408:27:03", "2014-11-1402:56:37", "2014-11-1315:59:11", "2014-11-1311:57:04", "2014-11-1310:01:57", "2014-11-1308:27:07", "2014-11-1304:43:58", "2014-11-1220:44:45", "2014-11-1219:29:11", "2014-11-1214:38:04", "2014-11-1213:44:10", "2014-11-1212:14:03", "2014-11-1211:05:14", "2014-11-1210:18:05", "2014-11-1202:42:10", "2014-11-1201:03:00", "2014-11-1122:45:56", "2014-11-1116:56:09", "2014-11-1111:34:12", "2014-11-1106:02:04", "2014-11-1102:02:03", "2014-11-1100:40:17", "2014-11-1023:28:10", "2014-11-1014:39:23", "2014-11-1010:49:04", "2014-11-1010:38:07", "2014-11-1003:03:12", "2014-11-0915:30:06", "2014-11-0914:30:47", "2014-11-0911:02:08", "2014-11-0810:30:10", "2014-11-0723:43:34", "2014-11-0711:28:08", "2014-11-0709:23:05", "2014-11-0619:29:06", "2014-11-0613:36:04", "2014-11-0611:27:08", "2014-11-0603:28:07", "2014-11-0516:58:05", "2014-11-0516:28:48", "2014-11-0514:32:11", "2014-11-0511:16:04", "2014-11-0511:05:40", "2014-11-0414:28:10", "2014-11-0414:23:12", "2014-11-0410:37:11" };
    int index = 0;

    foreach (VNTRSSItem* rssItem, rssChannel->getRSSItems()) {
        QCOMPARE(rssItem->getDate(), this->getSimpleDateFormatAtom(dates[index++]));
    }
}

void UnitTests::testAtomSiteBarItemTitle() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("atom-site-bar.xml");
    QString titles[] = { "qui aliqua sunt minim consequat deserunt", "non ullamco consequat in magna velit", "sit voluptate reprehenderit elit non nisi", "exercitation culpa voluptate elit exercitation minim", "sit magna duis dolore minim labore", "esse elit duis consequat irure cillum", "ad pariatur adipisicing id occaecat sint", "incididunt veniam laboris ipsum Lorem veniam", "velit nulla excepteur sunt culpa exercitation", "magna ad laborum ea consequat ullamco", "ullamco irure ea officia pariatur proident", "non veniam elit culpa cillum ea", "nulla quis deserunt ad proident nulla", "esse excepteur voluptate incididunt ea ea", "irure Lorem laborum elit laborum nulla", "duis non nisi cupidatat ut ea", "ut cupidatat sint nostrud veniam laboris", "culpa commodo enim velit tempor aliquip", "excepteur dolor eiusmod qui eu cillum", "nostrud velit proident cillum voluptate ex", "occaecat minim minim quis aliquip veniam", "dolor consequat aliqua veniam ad pariatur", "velit fugiat est nisi eiusmod velit", "adipisicing eu in Lorem occaecat pariatur", "ex enim laborum qui velit dolore", "cupidatat minim reprehenderit dolor sint duis", "aute dolor sunt proident laborum esse", "commodo voluptate velit est dolore eu", "pariatur aliqua et labore nisi ex", "adipisicing pariatur reprehenderit excepteur cupidatat nulla", "nulla fugiat adipisicing irure Lorem laborum", "incididunt veniam commodo laboris proident esse", "nulla cillum quis elit anim exercitation", "est enim id do velit id", "do exercitation excepteur quis pariatur sint", "esse sunt cillum culpa quis nostrud", "eu veniam eu consectetur tempor incididunt", "elit enim pariatur sunt duis pariatur", "reprehenderit dolor tempor irure dolore fugiat", "sunt mollit commodo velit sint dolor", "culpa veniam occaecat ea irure eu", "cupidatat Lorem amet reprehenderit irure eiusmod", "consequat occaecat sint reprehenderit veniam in", "amet aute commodo quis anim cupidatat", "fugiat culpa enim commodo non cupidatat", "commodo Lorem ad elit consequat id", "mollit fugiat commodo eiusmod aliquip fugiat", "deserunt culpa irure ex tempor quis", "deserunt enim nostrud fugiat eu fugiat", "irure ut veniam commodo consectetur est" };
    QString plainTitles[] = { "qui aliqua sunt minim consequat deserunt", "non ullamco consequat in magna velit", "sit voluptate reprehenderit elit non nisi", "exercitation culpa voluptate elit exercitation minim", "sit magna duis dolore minim labore", "esse elit duis consequat irure cillum", "ad pariatur adipisicing id occaecat sint", "incididunt veniam laboris ipsum Lorem veniam", "velit nulla excepteur sunt culpa exercitation", "magna ad laborum ea consequat ullamco", "ullamco irure ea officia pariatur proident", "non veniam elit culpa cillum ea", "nulla quis deserunt ad proident nulla", "esse excepteur voluptate incididunt ea ea", "irure Lorem laborum elit laborum nulla", "duis non nisi cupidatat ut ea", "ut cupidatat sint nostrud veniam laboris", "culpa commodo enim velit tempor aliquip", "excepteur dolor eiusmod qui eu cillum", "nostrud velit proident cillum voluptate ex", "occaecat minim minim quis aliquip veniam", "dolor consequat aliqua veniam ad pariatur", "velit fugiat est nisi eiusmod velit", "adipisicing eu in Lorem occaecat pariatur", "ex enim laborum qui velit dolore", "cupidatat minim reprehenderit dolor sint duis", "aute dolor sunt proident laborum esse", "commodo voluptate velit est dolore eu", "pariatur aliqua et labore nisi ex", "adipisicing pariatur reprehenderit excepteur cupidatat nulla", "nulla fugiat adipisicing irure Lorem laborum", "incididunt veniam commodo laboris proident esse", "nulla cillum quis elit anim exercitation", "est enim id do velit id", "do exercitation excepteur quis pariatur sint", "esse sunt cillum culpa quis nostrud", "eu veniam eu consectetur tempor incididunt", "elit enim pariatur sunt duis pariatur", "reprehenderit dolor tempor irure dolore fugiat", "sunt mollit commodo velit sint dolor", "culpa veniam occaecat ea irure eu", "cupidatat Lorem amet reprehenderit irure eiusmod", "consequat occaecat sint reprehenderit veniam in", "amet aute commodo quis anim cupidatat", "fugiat culpa enim commodo non cupidatat", "commodo Lorem ad elit consequat id", "mollit fugiat commodo eiusmod aliquip fugiat", "deserunt culpa irure ex tempor quis", "deserunt enim nostrud fugiat eu fugiat", "irure ut veniam commodo consectetur est" };
    int index = 0;

    foreach (VNTRSSItem* rssItem, rssChannel->getRSSItems()) {
        QCOMPARE(rssItem->getTitle(), titles[index]);
        QCOMPARE(rssItem->getPlainTitle(), plainTitles[index++]);
    }
}

void UnitTests::testAtomSiteBarItemDescription() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("atom-site-bar.xml");
    QString descriptions[] = { "<h4>culpa laboris cupidatat</h4> <p><strong>eu</strong>Qui fugiat ad consequat et qui duis. Dolore dolore cillum ullamco aliqua nostrud laboris. Voluptate commodo excepteur magna duis eu minim eiusmod exercitation. Ipsum laborum proident et voluptate dolore non amet elit pariatur Lorem. Eiusmod consequat aliqua ex adipisicing incididunt elit dolor laborum reprehenderit magna do sint. Irure ad aliqua proident aliquip est fugiat est est Lorem nostrud tempor dolor aliqua.</p>", "<h4>proident ut laborum</h4> <p><strong>Lorem</strong>Mollit nisi et sit laborum dolor labore anim minim ex nisi anim ex. Exercitation aliqua reprehenderit sint veniam do exercitation ad duis incididunt laboris. Adipisicing nulla tempor esse excepteur veniam.</p>", "<h4>excepteur voluptate in</h4> <p><strong>eu</strong>Non aute ea nisi est nisi consectetur ullamco anim. Occaecat duis sint laborum anim. Aliqua pariatur occaecat tempor amet eu ullamco dolore enim anim culpa consequat nulla. Voluptate cupidatat qui dolor ipsum elit cillum nostrud eiusmod quis officia ex. Incididunt proident ad dolore occaecat occaecat dolore proident exercitation proident.</p>", "<h4>incididunt ut consectetur</h4> <p><strong>magna</strong>Ex sit magna veniam quis ad consequat esse. Ullamco ipsum anim laborum culpa in incididunt. Anim eiusmod ad officia ullamco tempor excepteur. Occaecat minim reprehenderit et nostrud sunt. Aute sunt aliquip eiusmod reprehenderit sit labore voluptate aliqua enim voluptate aliquip nisi consequat.</p>", "<h4>ea dolor ex</h4> <p><strong>proident</strong>Magna consequat sunt amet do anim cillum dolor labore quis in reprehenderit ut laboris incididunt. Anim duis exercitation eu proident. Occaecat mollit amet ad do veniam amet laboris incididunt deserunt laborum culpa.</p>", "<h4>eiusmod ut anim</h4> <p><strong>aliquip</strong>Eiusmod qui voluptate labore laborum anim anim nostrud excepteur ea in mollit voluptate do laborum. Dolor voluptate anim ad qui ut eu adipisicing. Consequat ut cillum mollit eu irure magna fugiat labore. Pariatur ad sint deserunt et quis elit amet tempor sit. Ea sint commodo non tempor minim dolor cillum excepteur. Sint sit tempor mollit est ad sunt. Non ullamco do adipisicing ipsum consectetur ea qui sint et est amet.</p>", "<h4>in consequat cillum</h4> <p><strong>occaecat</strong>Irure cupidatat qui sint excepteur minim proident occaecat nisi id tempor amet. Veniam do enim elit dolore laborum laborum cillum excepteur eu ut ex velit adipisicing. Irure exercitation exercitation consectetur reprehenderit fugiat occaecat qui eiusmod nisi. Aliquip ut et adipisicing irure laboris qui velit ullamco amet. Eiusmod ad laboris reprehenderit nulla laborum tempor incididunt aute officia magna aliqua velit adipisicing consequat.</p>", "<h4>quis excepteur duis</h4> <p><strong>irure</strong>Aliqua proident nulla amet ullamco et nulla dolore fugiat pariatur. Sint occaecat adipisicing veniam nulla sint nisi pariatur. Magna irure reprehenderit est qui. Veniam aute ea fugiat est ex ad fugiat exercitation. In aliquip ullamco deserunt do tempor amet sunt qui dolor incididunt qui culpa ea. Ullamco id quis fugiat deserunt laborum exercitation duis.</p>", "<h4>cillum elit tempor</h4> <p><strong>nisi</strong>Nisi do fugiat sit occaecat aliqua. Adipisicing magna nostrud duis sit pariatur nulla fugiat adipisicing sit ad elit eiusmod. Voluptate enim officia sit ad sit aliquip qui est consequat qui mollit minim irure. Irure ut velit commodo duis enim. Culpa tempor aliqua tempor elit ut sunt amet laboris ex.</p>", "<h4>exercitation voluptate qui</h4> <p><strong>laboris</strong>Eiusmod non enim velit nulla eiusmod incididunt. Do laborum magna in laboris cupidatat aliquip magna velit sit ea ullamco. Nisi id irure occaecat culpa id non duis qui incididunt. Incididunt nisi laborum exercitation nulla deserunt esse esse ullamco labore. Id ut culpa occaecat proident proident aliqua quis. Nisi minim ut dolore in. Eiusmod occaecat duis est occaecat anim officia veniam commodo.</p>", "<h4>tempor eiusmod cupidatat</h4> <p><strong>nisi</strong>Enim aute voluptate deserunt cupidatat culpa minim ullamco deserunt aute. Minim nisi proident cupidatat amet excepteur in nisi fugiat sunt sunt. Magna cillum cupidatat aliquip commodo duis elit tempor amet commodo nostrud. Consequat magna anim magna adipisicing ad cillum mollit nisi ut magna officia duis quis. Commodo ex qui nostrud sunt velit aliquip est officia fugiat deserunt ex. Consequat deserunt incididunt aliqua irure Lorem. Commodo dolore irure eiusmod ad officia sint mollit ut exercitation esse ipsum tempor velit in.</p>", "<h4>in ut duis</h4> <p><strong>culpa</strong>Culpa ipsum ad deserunt tempor. Id dolore elit laborum eu velit velit exercitation reprehenderit fugiat tempor. Cillum enim mollit enim et. Consectetur qui dolore do voluptate.</p>", "<h4>pariatur labore proident</h4> <p><strong>qui</strong>Et id consequat adipisicing aliqua ad ipsum do id pariatur et duis do. Commodo in incididunt laboris adipisicing dolore tempor ut sint do ullamco tempor laborum. Reprehenderit veniam velit est incididunt Lorem proident ullamco sunt adipisicing sint. Cupidatat fugiat eu pariatur incididunt ea dolor fugiat aute deserunt fugiat laboris eu.</p>", "<h4>veniam voluptate esse</h4> <p><strong>reprehenderit</strong>Fugiat voluptate sunt nulla fugiat dolore exercitation sint occaecat excepteur pariatur nulla. Ex magna in nulla nulla elit aute esse anim occaecat et esse aliquip. Veniam non ipsum adipisicing commodo pariatur reprehenderit sit ad commodo sint. Pariatur irure adipisicing eiusmod non non reprehenderit. Qui est aliqua velit consectetur veniam ut aute. Consectetur sint excepteur commodo laborum exercitation irure deserunt quis voluptate aliquip. In ad culpa aute commodo non et id laborum sunt voluptate qui culpa duis.</p>", "<h4>sint proident quis</h4> <p><strong>proident</strong>Id dolor ea ad aliquip duis occaecat id mollit. Deserunt nulla exercitation sit deserunt laboris ullamco aute anim sint. Duis irure amet in cupidatat veniam et sit nisi eiusmod dolor laborum cupidatat exercitation. Quis sit dolore amet est ex sunt mollit cillum cillum. Sit dolor cupidatat ea nisi aliquip nisi ad est et laborum in minim eu commodo.</p>", "<h4>commodo esse consequat</h4> <p><strong>incididunt</strong>Fugiat Lorem ut sint aute dolore reprehenderit nostrud voluptate do nostrud occaecat in id. Laborum Lorem reprehenderit deserunt ullamco occaecat commodo Lorem exercitation sint nostrud quis duis cillum qui. Culpa do pariatur culpa eiusmod labore qui nostrud dolor laboris laborum sunt nulla eu. Pariatur ipsum cillum do irure id voluptate adipisicing incididunt officia.</p>", "<h4>magna ipsum tempor</h4> <p><strong>mollit</strong>Minim esse sit exercitation eiusmod non magna occaecat eiusmod laborum. Aliqua est cupidatat nulla velit non occaecat ut. Eu proident id nostrud adipisicing id reprehenderit do veniam laboris esse. Sunt nostrud sint tempor pariatur amet cupidatat esse non culpa.</p>", "<h4>enim labore sint</h4> <p><strong>dolore</strong>Ut incididunt ad consectetur dolor ipsum cillum. Mollit in ullamco aliqua aute cupidatat exercitation eiusmod ex irure enim id elit nostrud deserunt. Culpa velit aliquip labore elit pariatur. Ea minim laboris proident occaecat enim. Commodo pariatur elit laborum veniam ea adipisicing. Nulla irure ipsum officia mollit.</p>", "<h4>do voluptate ut</h4> <p><strong>ad</strong>Mollit non tempor quis id. Eiusmod sint sunt consectetur ad amet ut aliquip aliqua in aliqua officia. Veniam nulla occaecat est ipsum non Lorem Lorem tempor magna veniam anim irure. In nostrud duis ad dolore aute et. Ut est sit consequat ad mollit amet ea mollit. Culpa ut laboris culpa non voluptate sint excepteur.</p>", "<h4>eiusmod dolor in</h4> <p><strong>ea</strong>Velit labore amet aliquip commodo consectetur magna amet laboris exercitation consectetur dolore ut. Qui nulla sit adipisicing culpa ut elit et irure in in commodo nisi. Qui quis ex eiusmod eu ex sit aliquip dolor dolor et esse eu ut minim. Sunt Lorem Lorem duis excepteur ea nulla eu elit. Voluptate anim labore ipsum minim ipsum tempor est ut non nostrud duis.</p>", "<h4>cupidatat aliqua aliqua</h4> <p><strong>fugiat</strong>Esse proident magna anim ex dolor ullamco sit proident. Eu cillum Lorem consequat magna nostrud laborum proident esse irure dolore id velit. Enim est ut tempor et culpa eiusmod sit consectetur aliqua mollit id pariatur deserunt duis. Est non elit consequat ullamco enim esse eu sint. Veniam dolore veniam et qui sunt.</p>", "<h4>excepteur ullamco qui</h4> <p><strong>velit</strong>Eiusmod culpa fugiat veniam velit consequat adipisicing eu voluptate sit aute. Consequat dolor nulla ea sunt veniam pariatur. Anim id tempor aliqua esse mollit consequat nisi elit. Exercitation ea Lorem culpa dolore sint quis ad enim et irure incididunt aute qui. Occaecat voluptate ad dolor dolor velit Lorem veniam veniam aliquip occaecat sint.</p>", "<h4>Lorem reprehenderit occaecat</h4> <p><strong>minim</strong>Irure aliquip id cupidatat in pariatur ad. Non ad ullamco sunt cillum officia ad commodo dolore incididunt eu quis anim cupidatat ut. Excepteur consectetur mollit ea nostrud eu. Sint consectetur esse duis enim dolor amet et non qui.</p>", "<h4>consectetur veniam commodo</h4> <p><strong>excepteur</strong>Ipsum sint cillum irure enim officia cillum. Aliqua do occaecat officia enim culpa nulla ipsum dolor anim veniam excepteur qui. Commodo esse nulla commodo anim. Culpa ut ad ex aute elit qui Lorem officia commodo esse non adipisicing pariatur aliqua. Tempor qui irure labore velit.</p>", "<h4>Lorem est id</h4> <p><strong>laborum</strong>Veniam fugiat ex eu sit adipisicing voluptate quis veniam. Do consequat irure nulla nisi eiusmod id est do Lorem cupidatat. Nostrud elit non est reprehenderit esse enim exercitation Lorem laborum ad nulla dolore magna. Ex anim tempor elit velit officia nulla qui incididunt consectetur nisi ea. Ad dolore esse nulla aliqua quis tempor. Nulla est consequat nostrud eu. Duis excepteur enim ipsum reprehenderit consectetur sunt est ad sit est labore anim minim.</p>", "<h4>dolore cillum aliquip</h4> <p><strong>anim</strong>Esse eu occaecat consectetur ad ea reprehenderit est magna sunt consectetur. Minim culpa laboris eiusmod sit duis nisi eiusmod minim reprehenderit veniam nulla excepteur. Sit officia dolore ipsum sint laborum dolor qui elit consectetur nostrud deserunt aute tempor.</p>", "<h4>elit ullamco esse</h4> <p><strong>proident</strong>Nisi culpa sunt aute culpa voluptate cillum ex occaecat sunt nostrud reprehenderit sit. Amet dolore elit velit enim est aliqua laborum ullamco aliquip nostrud et culpa ullamco. Incididunt excepteur veniam proident pariatur laborum nostrud. Est sit irure voluptate ipsum pariatur magna magna aliquip mollit ipsum culpa. Reprehenderit duis ipsum elit dolor nisi reprehenderit tempor.</p>", "<h4>amet est eu</h4> <p><strong>laboris</strong>Amet officia veniam sint cupidatat quis occaecat cillum eiusmod laboris velit ut. In reprehenderit dolor commodo enim fugiat amet magna nulla eu labore amet dolor culpa proident. Ex consequat veniam occaecat sunt commodo ullamco esse culpa. Enim consequat velit excepteur sit qui exercitation irure irure adipisicing sit dolor magna occaecat ea. Quis nostrud ex ad amet magna laborum excepteur reprehenderit dolor quis eiusmod dolore. Laboris pariatur velit labore excepteur ipsum consectetur culpa quis consectetur duis officia exercitation fugiat.</p>", "<h4>adipisicing mollit in</h4> <p><strong>laborum</strong>Laborum irure ex laboris nisi reprehenderit qui consectetur ea voluptate qui exercitation. Nostrud ullamco do culpa laboris. Est non fugiat quis velit tempor aute. Excepteur voluptate cupidatat sit qui excepteur nisi exercitation aliquip do. Cupidatat deserunt consequat reprehenderit Lorem elit laborum velit voluptate nisi id nisi consequat.</p>", "<h4>veniam aliqua sunt</h4> <p><strong>cupidatat</strong>Culpa duis ullamco exercitation duis proident aliqua deserunt velit amet nulla dolore deserunt occaecat. Adipisicing incididunt ex nisi dolore ullamco nulla. Incididunt minim pariatur consequat duis deserunt.</p>", "<h4>mollit aliqua nulla</h4> <p><strong>voluptate</strong>Qui aliquip consectetur excepteur qui id ex cupidatat aliqua qui. Velit est fugiat cupidatat tempor et est sunt sint est. Pariatur ipsum mollit qui sit. Ea excepteur ullamco aliquip aliqua. Laboris irure minim Lorem velit est consequat eu ea laborum.</p>", "<h4>amet nostrud velit</h4> <p><strong>nisi</strong>Sint mollit commodo adipisicing ex eu amet deserunt et tempor reprehenderit nisi esse consequat enim. Do proident adipisicing do Lorem sunt irure enim consectetur culpa. Nulla nisi duis velit enim reprehenderit.</p>", "<h4>amet culpa labore</h4> <p><strong>ut</strong>Est culpa magna aliquip mollit sit excepteur nulla enim est minim sit duis. Pariatur exercitation cillum sint fugiat reprehenderit esse ipsum elit cupidatat incididunt cillum ut. Velit voluptate laborum ut tempor cupidatat voluptate consectetur ea cillum cillum consequat occaecat. Excepteur id ipsum Lorem nostrud do.</p>", "<h4>duis proident tempor</h4> <p><strong>eiusmod</strong>Aute esse nulla laborum consequat ullamco aute anim anim deserunt. Labore voluptate in aliqua ut nisi qui labore est eu consectetur. Aliqua cupidatat officia dolor do laboris tempor culpa do nostrud cupidatat minim cupidatat adipisicing. Lorem aute ut ea aute qui qui aliquip incididunt. Laborum ipsum esse eu voluptate ad ex. Lorem minim magna anim est ad do quis enim do pariatur Lorem culpa consequat in.</p>", "<h4>dolor culpa sint</h4> <p><strong>nisi</strong>Commodo sit minim sunt velit do irure ea officia officia eiusmod. Occaecat irure aliquip ipsum incididunt sit enim aliqua do labore proident voluptate eu. Nisi ut ea exercitation est tempor irure culpa et. Minim excepteur excepteur irure aute voluptate consequat enim. Magna ullamco pariatur est consequat in commodo. Culpa pariatur dolore nisi duis minim.</p>", "<h4>elit veniam aliqua</h4> <p><strong>proident</strong>Aute id ipsum exercitation excepteur laboris officia occaecat reprehenderit velit reprehenderit voluptate officia pariatur. Adipisicing Lorem Lorem est in quis aliquip enim voluptate occaecat. Laborum non reprehenderit irure aliqua ullamco consectetur tempor pariatur mollit ipsum.</p>", "<h4>sit laboris culpa</h4> <p><strong>nostrud</strong>Voluptate do excepteur laborum irure consectetur reprehenderit eu qui ut. Deserunt reprehenderit reprehenderit ea et in ipsum. Id commodo id sunt ex proident enim nulla. Laboris excepteur aute cupidatat eu et excepteur voluptate cillum aliquip sit ut officia proident ex. Eiusmod eiusmod nostrud dolor sit esse. Sunt mollit pariatur mollit ullamco quis excepteur enim sit. Nulla eiusmod sint amet veniam sint adipisicing incididunt nisi sint eu.</p>", "<h4>id ut non</h4> <p><strong>non</strong>Voluptate anim sunt enim amet incididunt. Do qui nulla voluptate irure laboris excepteur labore esse excepteur irure fugiat. Lorem dolor consequat officia deserunt culpa.</p>", "<h4>Lorem veniam tempor</h4> <p><strong>non</strong>Nulla sint esse excepteur ea enim veniam sit proident commodo aliqua est consequat id. Duis qui quis ipsum aliqua do nulla aliqua velit. Duis proident ipsum est cupidatat aliqua reprehenderit ex et Lorem amet amet. Labore labore enim in est quis mollit officia. Ex aute adipisicing aliquip duis.</p>", "<h4>labore Lorem eu</h4> <p><strong>est</strong>Magna et ut nostrud velit nisi velit amet. Reprehenderit laboris fugiat ex commodo dolor ut exercitation nostrud enim eiusmod adipisicing sunt exercitation reprehenderit. Officia sint consectetur laboris esse nisi proident sint. Laboris labore consequat in sunt sint cillum consequat duis. Deserunt nisi ut in labore.</p>", "<h4>id laboris ad</h4> <p><strong>tempor</strong>Quis nostrud Lorem ad ipsum labore laboris nisi consectetur aliquip officia ex veniam laborum laborum. Sint consectetur nulla laborum dolore velit ex aliquip voluptate exercitation dolor ullamco dolore ut consequat. Ut sunt eiusmod minim sint eu voluptate adipisicing sit do officia proident. Enim est ad id do occaecat do dolore sint nulla aliqua minim quis adipisicing. Nostrud voluptate nisi quis elit pariatur pariatur do eu magna sint. Ipsum irure pariatur reprehenderit occaecat. Officia do elit aliqua adipisicing cupidatat et consectetur id proident aute magna.</p>", "<h4>ullamco nisi fugiat</h4> <p><strong>labore</strong>Enim non officia id mollit reprehenderit ad est pariatur. Ad adipisicing culpa ipsum dolore mollit adipisicing cillum nostrud non et dolor sunt commodo. Reprehenderit mollit officia deserunt incididunt. Aute velit ipsum incididunt dolore. Nulla Lorem labore consectetur nulla duis qui incididunt nostrud culpa occaecat. Enim aliqua tempor proident ut aute aute minim velit quis nostrud incididunt aute qui. Mollit dolor dolore qui occaecat sint in veniam elit.</p>", "<h4>ut proident sit</h4> <p><strong>Lorem</strong>Aute Lorem id labore eu cillum veniam irure deserunt eu culpa ex voluptate dolor. Deserunt nisi ea incididunt eu veniam anim elit adipisicing duis. Est laboris nulla ullamco Lorem esse ea et eu.</p>", "<h4>minim consequat Lorem</h4> <p><strong>et</strong>Anim culpa culpa excepteur mollit voluptate aliquip est adipisicing. Irure consectetur consectetur deserunt fugiat et sint non id nisi elit. Anim laborum nisi officia magna ullamco incididunt consectetur ullamco velit anim excepteur tempor pariatur velit. Sunt esse ipsum labore ut deserunt est commodo magna consectetur dolor et occaecat. Id dolor est dolor duis. Qui velit Lorem fugiat est ex sunt reprehenderit dolore reprehenderit culpa occaecat duis nisi.</p>", "<h4>pariatur tempor voluptate</h4> <p><strong>id</strong>Eiusmod culpa minim id aliqua magna fugiat anim quis commodo esse proident. Ad commodo eiusmod aliquip mollit nostrud voluptate non eiusmod. Ipsum est tempor adipisicing enim veniam do aliqua minim sunt. Culpa culpa irure nulla consequat non ut officia irure aliqua est aliqua sunt et.</p>", "<h4>Lorem commodo reprehenderit</h4> <p><strong>ut</strong>Et irure consectetur ullamco ipsum ex do ipsum irure ipsum. Veniam amet magna ipsum cupidatat incididunt. Deserunt enim non laboris enim aute deserunt reprehenderit exercitation aute nostrud et sunt non nisi. Cillum exercitation nulla dolor veniam officia consequat in pariatur anim officia officia id laboris. Fugiat ullamco ipsum aute officia elit nostrud duis non dolore mollit magna esse laboris. Voluptate incididunt incididunt exercitation sit tempor duis Lorem.</p>", "<h4>ea anim voluptate</h4> <p><strong>nulla</strong>Culpa elit nisi pariatur fugiat officia deserunt eu nisi amet consequat. Aute ipsum consectetur est non ad sunt nostrud ut cupidatat incididunt mollit anim. Ullamco eiusmod duis anim aute aliquip enim proident consequat labore adipisicing qui mollit sunt. Sit elit culpa cillum deserunt ut ut dolor cupidatat minim id proident. Aute sit eu id id enim proident do aliqua.</p>", "<h4>minim eiusmod deserunt</h4> <p><strong>velit</strong>Elit sint incididunt commodo dolore exercitation. Voluptate ut excepteur in eiusmod aliqua anim voluptate incididunt ullamco ex deserunt magna. Mollit excepteur Lorem ea excepteur et eu mollit quis. Deserunt id occaecat tempor magna ipsum veniam.</p>", "<h4>sit cupidatat ipsum</h4> <p><strong>magna</strong>Aliquip irure tempor aute eu anim officia dolore tempor fugiat. Est nostrud cillum reprehenderit aliquip duis occaecat aute do eu tempor nisi labore. Tempor officia culpa dolor excepteur deserunt ullamco. Do ad labore cillum ullamco irure dolore Lorem adipisicing ex proident dolore ad.</p>", "<h4>officia et minim</h4> <p><strong>consequat</strong>Eu consectetur cillum incididunt mollit aliqua esse duis occaecat laboris pariatur. Ullamco mollit mollit eiusmod et exercitation sunt. Deserunt veniam laborum ipsum occaecat cillum. Proident deserunt veniam enim Lorem non in veniam adipisicing sunt.</p>" };
    QString plainDescriptions[] = { "culpa laboris cupidatat euQui fugiat ad consequat et qui duis. Dolore dolore cillum ullamco aliqua nostrud laboris. Voluptate commodo excepteur magna duis eu minim eiusmod exercitation. Ipsum laborum proident et voluptate dolore non amet elit pariatur Lorem. Eiusmod consequat aliqua ex adipisicing incididunt elit dolor laborum reprehenderit magna do sint. Irure ad aliqua proident aliquip est fugiat est est Lorem nostrud tempor dolor aliqua.", "proident ut laborum LoremMollit nisi et sit laborum dolor labore anim minim ex nisi anim ex. Exercitation aliqua reprehenderit sint veniam do exercitation ad duis incididunt laboris. Adipisicing nulla tempor esse excepteur veniam.", "excepteur voluptate in euNon aute ea nisi est nisi consectetur ullamco anim. Occaecat duis sint laborum anim. Aliqua pariatur occaecat tempor amet eu ullamco dolore enim anim culpa consequat nulla. Voluptate cupidatat qui dolor ipsum elit cillum nostrud eiusmod quis officia ex. Incididunt proident ad dolore occaecat occaecat dolore proident exercitation proident.", "incididunt ut consectetur magnaEx sit magna veniam quis ad consequat esse. Ullamco ipsum anim laborum culpa in incididunt. Anim eiusmod ad officia ullamco tempor excepteur. Occaecat minim reprehenderit et nostrud sunt. Aute sunt aliquip eiusmod reprehenderit sit labore voluptate aliqua enim voluptate aliquip nisi consequat.", "ea dolor ex proidentMagna consequat sunt amet do anim cillum dolor labore quis in reprehenderit ut laboris incididunt. Anim duis exercitation eu proident. Occaecat mollit amet ad do veniam amet laboris incididunt deserunt laborum culpa.", "eiusmod ut anim aliquipEiusmod qui voluptate labore laborum anim anim nostrud excepteur ea in mollit voluptate do laborum. Dolor voluptate anim ad qui ut eu adipisicing. Consequat ut cillum mollit eu irure magna fugiat labore. Pariatur ad sint deserunt et quis elit amet tempor sit. Ea sint commodo non tempor minim dolor cillum excepteur. Sint sit tempor mollit est ad sunt. Non ullamco do adipisicing ipsum consectetur ea qui sint et est amet.", "in consequat cillum occaecatIrure cupidatat qui sint excepteur minim proident occaecat nisi id tempor amet. Veniam do enim elit dolore laborum laborum cillum excepteur eu ut ex velit adipisicing. Irure exercitation exercitation consectetur reprehenderit fugiat occaecat qui eiusmod nisi. Aliquip ut et adipisicing irure laboris qui velit ullamco amet. Eiusmod ad laboris reprehenderit nulla laborum tempor incididunt aute officia magna aliqua velit adipisicing consequat.", "quis excepteur duis irureAliqua proident nulla amet ullamco et nulla dolore fugiat pariatur. Sint occaecat adipisicing veniam nulla sint nisi pariatur. Magna irure reprehenderit est qui. Veniam aute ea fugiat est ex ad fugiat exercitation. In aliquip ullamco deserunt do tempor amet sunt qui dolor incididunt qui culpa ea. Ullamco id quis fugiat deserunt laborum exercitation duis.", "cillum elit tempor nisiNisi do fugiat sit occaecat aliqua. Adipisicing magna nostrud duis sit pariatur nulla fugiat adipisicing sit ad elit eiusmod. Voluptate enim officia sit ad sit aliquip qui est consequat qui mollit minim irure. Irure ut velit commodo duis enim. Culpa tempor aliqua tempor elit ut sunt amet laboris ex.", "exercitation voluptate qui laborisEiusmod non enim velit nulla eiusmod incididunt. Do laborum magna in laboris cupidatat aliquip magna velit sit ea ullamco. Nisi id irure occaecat culpa id non duis qui incididunt. Incididunt nisi laborum exercitation nulla deserunt esse esse ullamco labore. Id ut culpa occaecat proident proident aliqua quis. Nisi minim ut dolore in. Eiusmod occaecat duis est occaecat anim officia veniam commodo.", "tempor eiusmod cupidatat nisiEnim aute voluptate deserunt cupidatat culpa minim ullamco deserunt aute. Minim nisi proident cupidatat amet excepteur in nisi fugiat sunt sunt. Magna cillum cupidatat aliquip commodo duis elit tempor amet commodo nostrud. Consequat magna anim magna adipisicing ad cillum mollit nisi ut magna officia duis quis. Commodo ex qui nostrud sunt velit aliquip est officia fugiat deserunt ex. Consequat deserunt incididunt aliqua irure Lorem. Commodo dolore irure eiusmod ad officia sint mollit ut exercitation esse ipsum tempor velit in.", "in ut duis culpaCulpa ipsum ad deserunt tempor. Id dolore elit laborum eu velit velit exercitation reprehenderit fugiat tempor. Cillum enim mollit enim et. Consectetur qui dolore do voluptate.", "pariatur labore proident quiEt id consequat adipisicing aliqua ad ipsum do id pariatur et duis do. Commodo in incididunt laboris adipisicing dolore tempor ut sint do ullamco tempor laborum. Reprehenderit veniam velit est incididunt Lorem proident ullamco sunt adipisicing sint. Cupidatat fugiat eu pariatur incididunt ea dolor fugiat aute deserunt fugiat laboris eu.", "veniam voluptate esse reprehenderitFugiat voluptate sunt nulla fugiat dolore exercitation sint occaecat excepteur pariatur nulla. Ex magna in nulla nulla elit aute esse anim occaecat et esse aliquip. Veniam non ipsum adipisicing commodo pariatur reprehenderit sit ad commodo sint. Pariatur irure adipisicing eiusmod non non reprehenderit. Qui est aliqua velit consectetur veniam ut aute. Consectetur sint excepteur commodo laborum exercitation irure deserunt quis voluptate aliquip. In ad culpa aute commodo non et id laborum sunt voluptate qui culpa duis.", "sint proident quis proidentId dolor ea ad aliquip duis occaecat id mollit. Deserunt nulla exercitation sit deserunt laboris ullamco aute anim sint. Duis irure amet in cupidatat veniam et sit nisi eiusmod dolor laborum cupidatat exercitation. Quis sit dolore amet est ex sunt mollit cillum cillum. Sit dolor cupidatat ea nisi aliquip nisi ad est et laborum in minim eu commodo.", "commodo esse consequat incididuntFugiat Lorem ut sint aute dolore reprehenderit nostrud voluptate do nostrud occaecat in id. Laborum Lorem reprehenderit deserunt ullamco occaecat commodo Lorem exercitation sint nostrud quis duis cillum qui. Culpa do pariatur culpa eiusmod labore qui nostrud dolor laboris laborum sunt nulla eu. Pariatur ipsum cillum do irure id voluptate adipisicing incididunt officia.", "magna ipsum tempor mollitMinim esse sit exercitation eiusmod non magna occaecat eiusmod laborum. Aliqua est cupidatat nulla velit non occaecat ut. Eu proident id nostrud adipisicing id reprehenderit do veniam laboris esse. Sunt nostrud sint tempor pariatur amet cupidatat esse non culpa.", "enim labore sint doloreUt incididunt ad consectetur dolor ipsum cillum. Mollit in ullamco aliqua aute cupidatat exercitation eiusmod ex irure enim id elit nostrud deserunt. Culpa velit aliquip labore elit pariatur. Ea minim laboris proident occaecat enim. Commodo pariatur elit laborum veniam ea adipisicing. Nulla irure ipsum officia mollit.", "do voluptate ut adMollit non tempor quis id. Eiusmod sint sunt consectetur ad amet ut aliquip aliqua in aliqua officia. Veniam nulla occaecat est ipsum non Lorem Lorem tempor magna veniam anim irure. In nostrud duis ad dolore aute et. Ut est sit consequat ad mollit amet ea mollit. Culpa ut laboris culpa non voluptate sint excepteur.", "eiusmod dolor in eaVelit labore amet aliquip commodo consectetur magna amet laboris exercitation consectetur dolore ut. Qui nulla sit adipisicing culpa ut elit et irure in in commodo nisi. Qui quis ex eiusmod eu ex sit aliquip dolor dolor et esse eu ut minim. Sunt Lorem Lorem duis excepteur ea nulla eu elit. Voluptate anim labore ipsum minim ipsum tempor est ut non nostrud duis.", "cupidatat aliqua aliqua fugiatEsse proident magna anim ex dolor ullamco sit proident. Eu cillum Lorem consequat magna nostrud laborum proident esse irure dolore id velit. Enim est ut tempor et culpa eiusmod sit consectetur aliqua mollit id pariatur deserunt duis. Est non elit consequat ullamco enim esse eu sint. Veniam dolore veniam et qui sunt.", "excepteur ullamco qui velitEiusmod culpa fugiat veniam velit consequat adipisicing eu voluptate sit aute. Consequat dolor nulla ea sunt veniam pariatur. Anim id tempor aliqua esse mollit consequat nisi elit. Exercitation ea Lorem culpa dolore sint quis ad enim et irure incididunt aute qui. Occaecat voluptate ad dolor dolor velit Lorem veniam veniam aliquip occaecat sint.", "Lorem reprehenderit occaecat minimIrure aliquip id cupidatat in pariatur ad. Non ad ullamco sunt cillum officia ad commodo dolore incididunt eu quis anim cupidatat ut. Excepteur consectetur mollit ea nostrud eu. Sint consectetur esse duis enim dolor amet et non qui.", "consectetur veniam commodo excepteurIpsum sint cillum irure enim officia cillum. Aliqua do occaecat officia enim culpa nulla ipsum dolor anim veniam excepteur qui. Commodo esse nulla commodo anim. Culpa ut ad ex aute elit qui Lorem officia commodo esse non adipisicing pariatur aliqua. Tempor qui irure labore velit.", "Lorem est id laborumVeniam fugiat ex eu sit adipisicing voluptate quis veniam. Do consequat irure nulla nisi eiusmod id est do Lorem cupidatat. Nostrud elit non est reprehenderit esse enim exercitation Lorem laborum ad nulla dolore magna. Ex anim tempor elit velit officia nulla qui incididunt consectetur nisi ea. Ad dolore esse nulla aliqua quis tempor. Nulla est consequat nostrud eu. Duis excepteur enim ipsum reprehenderit consectetur sunt est ad sit est labore anim minim.", "dolore cillum aliquip animEsse eu occaecat consectetur ad ea reprehenderit est magna sunt consectetur. Minim culpa laboris eiusmod sit duis nisi eiusmod minim reprehenderit veniam nulla excepteur. Sit officia dolore ipsum sint laborum dolor qui elit consectetur nostrud deserunt aute tempor.", "elit ullamco esse proidentNisi culpa sunt aute culpa voluptate cillum ex occaecat sunt nostrud reprehenderit sit. Amet dolore elit velit enim est aliqua laborum ullamco aliquip nostrud et culpa ullamco. Incididunt excepteur veniam proident pariatur laborum nostrud. Est sit irure voluptate ipsum pariatur magna magna aliquip mollit ipsum culpa. Reprehenderit duis ipsum elit dolor nisi reprehenderit tempor.", "amet est eu laborisAmet officia veniam sint cupidatat quis occaecat cillum eiusmod laboris velit ut. In reprehenderit dolor commodo enim fugiat amet magna nulla eu labore amet dolor culpa proident. Ex consequat veniam occaecat sunt commodo ullamco esse culpa. Enim consequat velit excepteur sit qui exercitation irure irure adipisicing sit dolor magna occaecat ea. Quis nostrud ex ad amet magna laborum excepteur reprehenderit dolor quis eiusmod dolore. Laboris pariatur velit labore excepteur ipsum consectetur culpa quis consectetur duis officia exercitation fugiat.", "adipisicing mollit in laborumLaborum irure ex laboris nisi reprehenderit qui consectetur ea voluptate qui exercitation. Nostrud ullamco do culpa laboris. Est non fugiat quis velit tempor aute. Excepteur voluptate cupidatat sit qui excepteur nisi exercitation aliquip do. Cupidatat deserunt consequat reprehenderit Lorem elit laborum velit voluptate nisi id nisi consequat.", "veniam aliqua sunt cupidatatCulpa duis ullamco exercitation duis proident aliqua deserunt velit amet nulla dolore deserunt occaecat. Adipisicing incididunt ex nisi dolore ullamco nulla. Incididunt minim pariatur consequat duis deserunt.", "mollit aliqua nulla voluptateQui aliquip consectetur excepteur qui id ex cupidatat aliqua qui. Velit est fugiat cupidatat tempor et est sunt sint est. Pariatur ipsum mollit qui sit. Ea excepteur ullamco aliquip aliqua. Laboris irure minim Lorem velit est consequat eu ea laborum.", "amet nostrud velit nisiSint mollit commodo adipisicing ex eu amet deserunt et tempor reprehenderit nisi esse consequat enim. Do proident adipisicing do Lorem sunt irure enim consectetur culpa. Nulla nisi duis velit enim reprehenderit.", "amet culpa labore utEst culpa magna aliquip mollit sit excepteur nulla enim est minim sit duis. Pariatur exercitation cillum sint fugiat reprehenderit esse ipsum elit cupidatat incididunt cillum ut. Velit voluptate laborum ut tempor cupidatat voluptate consectetur ea cillum cillum consequat occaecat. Excepteur id ipsum Lorem nostrud do.", "duis proident tempor eiusmodAute esse nulla laborum consequat ullamco aute anim anim deserunt. Labore voluptate in aliqua ut nisi qui labore est eu consectetur. Aliqua cupidatat officia dolor do laboris tempor culpa do nostrud cupidatat minim cupidatat adipisicing. Lorem aute ut ea aute qui qui aliquip incididunt. Laborum ipsum esse eu voluptate ad ex. Lorem minim magna anim est ad do quis enim do pariatur Lorem culpa consequat in.", "dolor culpa sint nisiCommodo sit minim sunt velit do irure ea officia officia eiusmod. Occaecat irure aliquip ipsum incididunt sit enim aliqua do labore proident voluptate eu. Nisi ut ea exercitation est tempor irure culpa et. Minim excepteur excepteur irure aute voluptate consequat enim. Magna ullamco pariatur est consequat in commodo. Culpa pariatur dolore nisi duis minim.", "elit veniam aliqua proidentAute id ipsum exercitation excepteur laboris officia occaecat reprehenderit velit reprehenderit voluptate officia pariatur. Adipisicing Lorem Lorem est in quis aliquip enim voluptate occaecat. Laborum non reprehenderit irure aliqua ullamco consectetur tempor pariatur mollit ipsum.", "sit laboris culpa nostrudVoluptate do excepteur laborum irure consectetur reprehenderit eu qui ut. Deserunt reprehenderit reprehenderit ea et in ipsum. Id commodo id sunt ex proident enim nulla. Laboris excepteur aute cupidatat eu et excepteur voluptate cillum aliquip sit ut officia proident ex. Eiusmod eiusmod nostrud dolor sit esse. Sunt mollit pariatur mollit ullamco quis excepteur enim sit. Nulla eiusmod sint amet veniam sint adipisicing incididunt nisi sint eu.", "id ut non nonVoluptate anim sunt enim amet incididunt. Do qui nulla voluptate irure laboris excepteur labore esse excepteur irure fugiat. Lorem dolor consequat officia deserunt culpa.", "Lorem veniam tempor nonNulla sint esse excepteur ea enim veniam sit proident commodo aliqua est consequat id. Duis qui quis ipsum aliqua do nulla aliqua velit. Duis proident ipsum est cupidatat aliqua reprehenderit ex et Lorem amet amet. Labore labore enim in est quis mollit officia. Ex aute adipisicing aliquip duis.", "labore Lorem eu estMagna et ut nostrud velit nisi velit amet. Reprehenderit laboris fugiat ex commodo dolor ut exercitation nostrud enim eiusmod adipisicing sunt exercitation reprehenderit. Officia sint consectetur laboris esse nisi proident sint. Laboris labore consequat in sunt sint cillum consequat duis. Deserunt nisi ut in labore.", "id laboris ad temporQuis nostrud Lorem ad ipsum labore laboris nisi consectetur aliquip officia ex veniam laborum laborum. Sint consectetur nulla laborum dolore velit ex aliquip voluptate exercitation dolor ullamco dolore ut consequat. Ut sunt eiusmod minim sint eu voluptate adipisicing sit do officia proident. Enim est ad id do occaecat do dolore sint nulla aliqua minim quis adipisicing. Nostrud voluptate nisi quis elit pariatur pariatur do eu magna sint. Ipsum irure pariatur reprehenderit occaecat. Officia do elit aliqua adipisicing cupidatat et consectetur id proident aute magna.", "ullamco nisi fugiat laboreEnim non officia id mollit reprehenderit ad est pariatur. Ad adipisicing culpa ipsum dolore mollit adipisicing cillum nostrud non et dolor sunt commodo. Reprehenderit mollit officia deserunt incididunt. Aute velit ipsum incididunt dolore. Nulla Lorem labore consectetur nulla duis qui incididunt nostrud culpa occaecat. Enim aliqua tempor proident ut aute aute minim velit quis nostrud incididunt aute qui. Mollit dolor dolore qui occaecat sint in veniam elit.", "ut proident sit LoremAute Lorem id labore eu cillum veniam irure deserunt eu culpa ex voluptate dolor. Deserunt nisi ea incididunt eu veniam anim elit adipisicing duis. Est laboris nulla ullamco Lorem esse ea et eu.", "minim consequat Lorem etAnim culpa culpa excepteur mollit voluptate aliquip est adipisicing. Irure consectetur consectetur deserunt fugiat et sint non id nisi elit. Anim laborum nisi officia magna ullamco incididunt consectetur ullamco velit anim excepteur tempor pariatur velit. Sunt esse ipsum labore ut deserunt est commodo magna consectetur dolor et occaecat. Id dolor est dolor duis. Qui velit Lorem fugiat est ex sunt reprehenderit dolore reprehenderit culpa occaecat duis nisi.", "pariatur tempor voluptate idEiusmod culpa minim id aliqua magna fugiat anim quis commodo esse proident. Ad commodo eiusmod aliquip mollit nostrud voluptate non eiusmod. Ipsum est tempor adipisicing enim veniam do aliqua minim sunt. Culpa culpa irure nulla consequat non ut officia irure aliqua est aliqua sunt et.", "Lorem commodo reprehenderit utEt irure consectetur ullamco ipsum ex do ipsum irure ipsum. Veniam amet magna ipsum cupidatat incididunt. Deserunt enim non laboris enim aute deserunt reprehenderit exercitation aute nostrud et sunt non nisi. Cillum exercitation nulla dolor veniam officia consequat in pariatur anim officia officia id laboris. Fugiat ullamco ipsum aute officia elit nostrud duis non dolore mollit magna esse laboris. Voluptate incididunt incididunt exercitation sit tempor duis Lorem.", "ea anim voluptate nullaCulpa elit nisi pariatur fugiat officia deserunt eu nisi amet consequat. Aute ipsum consectetur est non ad sunt nostrud ut cupidatat incididunt mollit anim. Ullamco eiusmod duis anim aute aliquip enim proident consequat labore adipisicing qui mollit sunt. Sit elit culpa cillum deserunt ut ut dolor cupidatat minim id proident. Aute sit eu id id enim proident do aliqua.", "minim eiusmod deserunt velitElit sint incididunt commodo dolore exercitation. Voluptate ut excepteur in eiusmod aliqua anim voluptate incididunt ullamco ex deserunt magna. Mollit excepteur Lorem ea excepteur et eu mollit quis. Deserunt id occaecat tempor magna ipsum veniam.", "sit cupidatat ipsum magnaAliquip irure tempor aute eu anim officia dolore tempor fugiat. Est nostrud cillum reprehenderit aliquip duis occaecat aute do eu tempor nisi labore. Tempor officia culpa dolor excepteur deserunt ullamco. Do ad labore cillum ullamco irure dolore Lorem adipisicing ex proident dolore ad.", "officia et minim consequatEu consectetur cillum incididunt mollit aliqua esse duis occaecat laboris pariatur. Ullamco mollit mollit eiusmod et exercitation sunt. Deserunt veniam laborum ipsum occaecat cillum. Proident deserunt veniam enim Lorem non in veniam adipisicing sunt." };
    int index = 0;

    foreach (VNTRSSItem* rssItem, rssChannel->getRSSItems()) {
        QCOMPARE(rssItem->getDescription(), descriptions[index]);
        QCOMPARE(rssItem->getPlainDescription(), plainDescriptions[index++]);
    }
}

void UnitTests::testAtomSiteExampleDate() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("atom-site-example.xml");
    QCOMPARE(rssChannel->getDate(), this->getSimpleDateFormatAtom("2014-11-1419:10:03"));
}

void UnitTests::testAtomSiteExampleLink() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("atom-site-example.xml");
    QCOMPARE(rssChannel->getLink(), QUrl("http://www.example.org/"));
}

void UnitTests::testAtomSiteExampleImageInternet() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("atom-site-example.xml");
    QCOMPARE(rssChannel->getImageUrl(), QUrl("http://www.example.org/rss.png"));
    QCOMPARE(rssChannel->getImageFileType(), QString("png"));
}

void UnitTests::testAtomSiteExampleLanguage() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("atom-site-example.xml");
    QCOMPARE(rssChannel->getLanguage(), QString("en"));
}

void UnitTests::testAtomSiteExampleTitle() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("atom-site-example.xml");
    QCOMPARE(rssChannel->getTitle(), QString("Example title"));
    QCOMPARE(rssChannel->getPlainTitle(), QString("Example title"));
}

void UnitTests::testAtomSiteExampleDescription() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("atom-site-example.xml");
    QCOMPARE(rssChannel->getDescription(), QString("Example description"));
    QCOMPARE(rssChannel->getPlainDescription(), QString("Example description"));
}

void UnitTests::testAtomSiteExampleItemSize() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("atom-site-example.xml");
    QList<VNTRSSItem*> rssItems = rssChannel->getRSSItems();
    QCOMPARE(rssItems.size(), 40);
}

void UnitTests::testAtomSiteExampleItemLink() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("atom-site-example.xml");
    QString links[] = { "http://www.example.org/news/c90b8f7e-a153-469f.html", "http://www.example.org/news/ce4de44e-0ede-4d7a.html", "http://www.example.org/news/2d4b982f-ab39-4cac.html", "http://www.example.org/news/37c51c24-acce-44c9.html", "http://www.example.org/news/82fe69cd-f50c-43b5.html", "http://www.example.org/news/689118be-15a3-4438.html", "http://www.example.org/news/34b90018-c7f1-4e9d.html", "http://www.example.org/news/3dad3760-3341-4560.html", "http://www.example.org/news/33ed6b85-b3a4-4ae0.html", "http://www.example.org/news/84b845a3-feb2-4e53.html", "http://www.example.org/news/702dee44-ea87-455e.html", "http://www.example.org/news/11991188-e091-4486.html", "http://www.example.org/news/92c6aa7a-d0d2-48f3.html", "http://www.example.org/news/902d9b5a-a1ea-4d65.html", "http://www.example.org/news/05688886-88a5-4a02.html", "http://www.example.org/news/841d4cc0-4653-4715.html", "http://www.example.org/news/c7d279ae-1f59-452f.html", "http://www.example.org/news/c4ce30e9-0bdd-45ba.html", "http://www.example.org/news/b12785dc-84aa-4c2f.html", "http://www.example.org/news/1ff0ceb0-954d-4715.html", "http://www.example.org/news/9f5aaff5-e391-4c96.html", "http://www.example.org/news/b9382125-c457-4719.html", "http://www.example.org/news/ab36dc34-c6c4-466c.html", "http://www.example.org/news/5edb5bbd-d23d-434b.html", "http://www.example.org/news/717569fe-023b-4f21.html", "http://www.example.org/news/f4d3aab1-42cf-453b.html", "http://www.example.org/news/5e72987f-788c-4c56.html", "http://www.example.org/news/dfbbfba3-395c-470d.html", "http://www.example.org/news/1daf0fd4-c57f-4755.html", "http://www.example.org/news/0bdae745-ad6b-4184.html", "http://www.example.org/news/1e6143da-5c7f-4e5b.html", "http://www.example.org/news/8bf6b434-dda0-4d46.html", "http://www.example.org/news/0bb772c9-0b5c-495b.html", "http://www.example.org/news/ec03d3a6-0f79-48bb.html", "http://www.example.org/news/756e5d29-53cf-403e.html", "http://www.example.org/news/408972de-c5bc-41b3.html", "http://www.example.org/news/4b43f3e0-aade-4d32.html", "http://www.example.org/news/a4f2018c-9d94-498e.html", "http://www.example.org/news/37ce57c1-e739-45c6.html", "http://www.example.org/news/5b29eebb-f8a2-4a6e.html" };
    int index = 0;

    foreach (VNTRSSItem* rssItem, rssChannel->getRSSItems()) {
        QCOMPARE(rssItem->getLink(), QUrl(links[index++]));
    }
}

void UnitTests::testAtomSiteExampleItemDate() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("atom-site-example.xml");
    QString dates[] = { "2014-11-1416:56:07", "2014-11-1416:33:05", "2014-11-1415:55:06", "2014-11-1415:49:04", "2014-11-1415:15:03", "2014-11-1415:00:02", "2014-11-1414:53:01", "2014-11-1414:35:00", "2014-11-1413:33:09", "2014-11-1413:21:08", "2014-11-1412:48:07", "2014-11-1412:16:06", "2014-11-1412:10:05", "2014-11-1411:59:07", "2014-11-1411:53:04", "2014-11-1411:39:03", "2014-11-1411:35:02", "2014-11-1410:47:08", "2014-11-1410:36:01", "2014-11-1409:48:00", "2014-11-1409:37:09", "2014-11-1408:53:06", "2014-11-1408:00:01", "2014-11-1408:00:04", "2014-11-1407:41:04", "2014-11-1407:31:03", "2014-11-1407:16:05", "2014-11-1407:06:02", "2014-11-1318:22:08", "2014-11-1318:00:07", "2014-11-1317:37:07", "2014-11-1317:06:05", "2014-11-1316:54:06", "2014-11-1316:33:04", "2014-11-1315:57:05", "2014-11-1315:09:03", "2014-11-1315:04:01", "2014-11-1315:01:04", "2014-11-1314:38:02", "2014-11-1314:06:07" };
    int index = 0;

    foreach (VNTRSSItem* rssItem, rssChannel->getRSSItems()) {
        QCOMPARE(rssItem->getDate(), this->getSimpleDateFormatAtom(dates[index++]));
    }
}

void UnitTests::testAtomSiteExampleItemTitle() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("atom-site-example.xml");
    QString titles[] = { "adipisicing culpa elit ipsum veniam cupidatat non", "nulla ipsum excepteur sunt dolor enim aliquip", "veniam esse proident id Lorem est nulla", "quis eu commodo voluptate qui dolor sunt", "quis ut cillum fugiat ut laborum nulla", "exercitation anim do anim ea excepteur cupidatat", "ea velit pariatur est ad eiusmod incididunt", "nostrud laborum voluptate in nulla Lorem Lorem", "ullamco dolore sit do ut est voluptate", "est irure eu non ut enim quis", "tempor nisi voluptate commodo fugiat dolor officia", "ut ullamco magna voluptate minim proident nulla", "irure non ad duis exercitation commodo aute", "esse enim voluptate irure aliqua aliqua nostrud", "est aute aliqua ex officia duis laboris", "anim adipisicing nulla qui deserunt cupidatat non", "eu magna nulla do adipisicing aliquip excepteur", "aliquip dolore excepteur ea sit laboris voluptate", "laboris ut amet consectetur consequat aute veniam", "et eiusmod laborum excepteur velit excepteur eiusmod", "esse excepteur incididunt culpa in in minim", "minim laboris eu nisi ipsum culpa cupidatat", "incididunt sint eu aliquip do exercitation ex", "qui id pariatur do in officia commodo", "ut quis commodo duis nostrud commodo id", "exercitation cillum elit id deserunt veniam cupidatat", "officia qui aliqua id velit laborum consectetur", "nostrud qui proident sunt enim aliquip adipisicing", "fugiat commodo labore ex dolor ad adipisicing", "nisi laborum ex ea velit consequat reprehenderit", "proident Lorem magna et nulla id fugiat", "culpa pariatur enim deserunt voluptate sit aliqua", "nostrud veniam aliqua sint pariatur aliqua pariatur", "tempor est officia dolore sunt tempor id", "ut ex adipisicing ullamco nostrud amet in", "laboris ea cupidatat exercitation quis Lorem laborum", "fugiat quis reprehenderit duis laboris tempor amet", "magna commodo do in aliqua laborum est", "ullamco id sint minim eiusmod proident irure", "voluptate adipisicing adipisicing occaecat aute anim voluptate" };
    QString plainTitles[] = { "adipisicing culpa elit ipsum veniam cupidatat non", "nulla ipsum excepteur sunt dolor enim aliquip", "veniam esse proident id Lorem est nulla", "quis eu commodo voluptate qui dolor sunt", "quis ut cillum fugiat ut laborum nulla", "exercitation anim do anim ea excepteur cupidatat", "ea velit pariatur est ad eiusmod incididunt", "nostrud laborum voluptate in nulla Lorem Lorem", "ullamco dolore sit do ut est voluptate", "est irure eu non ut enim quis", "tempor nisi voluptate commodo fugiat dolor officia", "ut ullamco magna voluptate minim proident nulla", "irure non ad duis exercitation commodo aute", "esse enim voluptate irure aliqua aliqua nostrud", "est aute aliqua ex officia duis laboris", "anim adipisicing nulla qui deserunt cupidatat non", "eu magna nulla do adipisicing aliquip excepteur", "aliquip dolore excepteur ea sit laboris voluptate", "laboris ut amet consectetur consequat aute veniam", "et eiusmod laborum excepteur velit excepteur eiusmod", "esse excepteur incididunt culpa in in minim", "minim laboris eu nisi ipsum culpa cupidatat", "incididunt sint eu aliquip do exercitation ex", "qui id pariatur do in officia commodo", "ut quis commodo duis nostrud commodo id", "exercitation cillum elit id deserunt veniam cupidatat", "officia qui aliqua id velit laborum consectetur", "nostrud qui proident sunt enim aliquip adipisicing", "fugiat commodo labore ex dolor ad adipisicing", "nisi laborum ex ea velit consequat reprehenderit", "proident Lorem magna et nulla id fugiat", "culpa pariatur enim deserunt voluptate sit aliqua", "nostrud veniam aliqua sint pariatur aliqua pariatur", "tempor est officia dolore sunt tempor id", "ut ex adipisicing ullamco nostrud amet in", "laboris ea cupidatat exercitation quis Lorem laborum", "fugiat quis reprehenderit duis laboris tempor amet", "magna commodo do in aliqua laborum est", "ullamco id sint minim eiusmod proident irure", "voluptate adipisicing adipisicing occaecat aute anim voluptate" };
    int index = 0;

    foreach (VNTRSSItem* rssItem, rssChannel->getRSSItems()) {
        QCOMPARE(rssItem->getTitle(), titles[index]);
        QCOMPARE(rssItem->getPlainTitle(), plainTitles[index++]);
    }
}

void UnitTests::testAtomSiteExampleItemDescription() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("atom-site-example.xml");
    QString descriptions[] = { "Et aliquip et amet duis aliquip Lorem mollit velit amet pariatur. Reprehenderit incididunt occaecat ex nostrud amet sit nulla tempor nulla sit consequat enim. Pariatur culpa ad commodo reprehenderit ipsum amet consectetur officia et. Sint incididunt laborum ad ea id dolore ex do labore aliqua magna. Deserunt aliqua duis sunt laborum nisi aute deserunt officia elit sunt tempor ex velit et. Non dolore commodo commodo ex nostrud incididunt. Consequat est exercitation id tempor nostrud esse enim ea laboris aute commodo eu laborum. (<a href=\"http://example.org/tags/eiusmod\">eiusmod</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Ea exercitation laborum sunt dolore aliquip irure reprehenderit duis ex nulla cupidatat reprehenderit sunt. Ullamco deserunt aute officia eiusmod amet nulla labore culpa ullamco cillum aute ullamco quis est. Elit ullamco duis ipsum culpa eu deserunt et deserunt ea in est sint sint irure. Excepteur culpa sint nulla est labore aute ut reprehenderit ex ullamco nisi aliquip. Minim proident aliquip aute quis mollit id. Occaecat sit ea duis magna anim mollit nulla sit proident tempor adipisicing officia. Commodo duis cillum et Lorem incididunt tempor eu. (<a href=\"http://example.org/tags/ipsum\">ipsum</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Ut Lorem nostrud duis sit nulla sint. Labore Lorem ullamco nostrud sint laborum incididunt velit adipisicing. Eiusmod sunt esse qui nulla ullamco reprehenderit commodo ex nostrud aliquip ipsum esse laboris reprehenderit. (<a href=\"http://example.org/tags/tempor\">tempor</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Ipsum Lorem nulla deserunt non ex deserunt cupidatat nostrud aliqua incididunt laborum amet ut excepteur. Ea labore magna labore incididunt eu cillum aliquip do do. Duis quis laborum ea incididunt non. (<a href=\"http://example.org/tags/ea\">ea</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Nisi quis tempor et consequat eu magna ipsum quis nostrud in fugiat cupidatat consequat. Cupidatat non adipisicing enim est deserunt ullamco ea consectetur ipsum ea aute. Mollit eiusmod dolore cillum enim. Anim ipsum aute est sit mollit non commodo irure laboris consectetur. Esse qui consectetur voluptate esse id ut et excepteur non commodo pariatur labore amet incididunt. Lorem consequat qui Lorem enim officia ea mollit ut mollit. Adipisicing duis et id sint aliqua sint. (<a href=\"http://example.org/tags/id\">id</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Deserunt id dolor nulla ex voluptate ad ex culpa. Ea magna est nulla eu voluptate. Nisi consectetur ea fugiat officia elit eiusmod non. Ipsum eiusmod officia sunt voluptate fugiat irure amet. Tempor nisi consectetur cupidatat reprehenderit ullamco. Occaecat fugiat irure minim enim consequat minim culpa. Ut excepteur enim veniam laborum irure. (<a href=\"http://example.org/tags/labore\">labore</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Aute adipisicing adipisicing ex amet elit laboris sunt dolor enim est duis magna excepteur aute. Tempor tempor ad non commodo anim id ea. Minim irure qui dolor veniam nulla ex reprehenderit cillum exercitation consequat quis laboris anim. (<a href=\"http://example.org/tags/nulla\">nulla</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Aliquip aute irure eiusmod deserunt pariatur occaecat. Ex eiusmod elit aliqua id officia ipsum deserunt duis incididunt enim non consectetur proident do. Ut eu pariatur consectetur mollit. (<a href=\"http://example.org/tags/nostrud\">nostrud</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Enim excepteur tempor Lorem duis anim nulla irure. Officia nulla non culpa enim do ut occaecat eu minim dolore laborum reprehenderit consequat occaecat. Et quis do adipisicing dolore sit aute. In deserunt laboris qui nostrud consequat esse. Non enim velit ipsum non laboris esse do duis eiusmod veniam voluptate. Pariatur tempor occaecat elit qui reprehenderit aute ullamco ex nulla. Ex sint sint nostrud excepteur aliqua anim cillum id ipsum Lorem sint et. (<a href=\"http://example.org/tags/consectetur\">consectetur</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Aute ex consectetur ex duis. Incididunt incididunt est eu cillum velit sint incididunt nulla officia irure occaecat ea deserunt eiusmod. Ut ea tempor ex sint reprehenderit. Eiusmod cupidatat officia dolor proident. (<a href=\"http://example.org/tags/exercitation\">exercitation</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Id officia qui id non enim incididunt. Esse duis excepteur laboris voluptate cillum. Nisi est anim laboris voluptate consequat cupidatat pariatur nulla esse. Sit officia est irure incididunt. (<a href=\"http://example.org/tags/dolore\">dolore</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Duis mollit cupidatat minim et commodo dolor in qui magna dolore. Occaecat duis officia ut labore ex mollit Lorem laborum qui deserunt eiusmod. Minim quis nulla non cupidatat dolore ea ex officia in magna reprehenderit proident non excepteur. Reprehenderit dolor sit sint est id cillum consectetur Lorem laboris anim mollit. (<a href=\"http://example.org/tags/fugiat\">fugiat</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Est nulla eu occaecat incididunt deserunt. Nulla in eu consectetur amet minim sint in ullamco non esse. Ullamco sunt consequat ad culpa do minim ut quis veniam ullamco nulla. Lorem pariatur sint irure aliqua est exercitation elit amet. Minim mollit cillum consequat consequat eu ex. Cillum ad sit anim sit nulla dolor esse ea est. Quis officia consectetur eiusmod exercitation duis eiusmod mollit consectetur ullamco aliqua non mollit mollit fugiat. (<a href=\"http://example.org/tags/est\">est</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Do laborum laboris cupidatat consectetur mollit. Lorem magna anim irure irure officia culpa sunt exercitation irure consequat. Nisi tempor fugiat et pariatur qui est ullamco amet consequat incididunt duis. Qui consectetur dolore ex nulla ad fugiat pariatur ipsum occaecat est Lorem laboris. (<a href=\"http://example.org/tags/laboris\">laboris</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "In tempor ea nostrud excepteur cillum magna eu. Ad minim occaecat eu cillum ea irure dolore est aliquip quis. Cillum est cupidatat id nostrud exercitation qui in ullamco nulla eiusmod aliquip. Aute nostrud nostrud ad sint ex sit quis qui deserunt incididunt pariatur dolore reprehenderit voluptate. Ad id amet sunt culpa sint laborum proident sint. Tempor sunt qui anim ut. (<a href=\"http://example.org/tags/reprehenderit\">reprehenderit</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Ex proident anim elit labore sint ea dolor ea voluptate duis eu pariatur velit. Fugiat eu eiusmod dolore labore aliquip irure officia. Elit labore sint excepteur commodo veniam in ullamco commodo aliqua sint dolor ullamco et. Laboris dolore fugiat pariatur sint duis ipsum velit mollit. Aute sunt enim exercitation elit quis exercitation. Est voluptate voluptate est nisi reprehenderit ea. Sunt enim exercitation reprehenderit labore est veniam excepteur occaecat fugiat incididunt est aute. (<a href=\"http://example.org/tags/ipsum\">ipsum</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Commodo dolore mollit velit sunt adipisicing officia. Ut culpa aliqua ipsum cupidatat dolor consequat. Labore laboris velit officia est aliquip. Consequat esse amet laborum exercitation dolor consectetur non sunt consectetur cillum tempor laboris. Cupidatat enim eiusmod culpa qui ad est aliqua laboris. Sint adipisicing et proident sunt enim excepteur cillum fugiat culpa. (<a href=\"http://example.org/tags/ipsum\">ipsum</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Labore esse esse nisi adipisicing sit occaecat exercitation. Cillum sint excepteur ad non ex consectetur. In irure qui magna velit non. Do sunt magna ipsum anim quis culpa cillum. Incididunt ipsum ad deserunt esse et aliquip aute nostrud tempor in eiusmod quis. Eiusmod voluptate magna commodo elit anim. Irure ut dolor labore ea minim irure deserunt esse. (<a href=\"http://example.org/tags/culpa\">culpa</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Esse irure mollit elit tempor duis eiusmod irure laborum in ad culpa reprehenderit id Lorem. Aute nisi eiusmod culpa sunt esse. Deserunt duis ea ut minim commodo duis officia aliqua veniam ex. Nulla consequat minim irure elit. Sit laboris magna minim ipsum. Tempor aute cillum ut dolor reprehenderit aute reprehenderit occaecat commodo cillum duis. Minim sit et nisi sunt dolore sunt duis incididunt consectetur quis sint consequat. (<a href=\"http://example.org/tags/veniam\">veniam</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Lorem id est dolore ea amet. Eiusmod esse occaecat deserunt mollit aliqua veniam. Incididunt ex quis qui in proident amet magna commodo id voluptate duis eu dolore proident. Anim dolore voluptate minim minim veniam consectetur aliquip enim. Labore do proident non aute velit consequat consectetur in ipsum id id incididunt cupidatat adipisicing. (<a href=\"http://example.org/tags/ut\">ut</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Veniam nisi laboris et aute veniam aliquip elit anim commodo nisi. Tempor magna sunt deserunt veniam aliquip nisi amet magna. Cupidatat Lorem excepteur mollit sunt veniam voluptate duis et ipsum deserunt esse reprehenderit. (<a href=\"http://example.org/tags/quis\">quis</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Fugiat fugiat eu mollit aliqua culpa nostrud deserunt irure officia est culpa duis Lorem veniam. Elit Lorem tempor enim Lorem adipisicing. Qui eu culpa dolor eiusmod consequat incididunt ullamco dolor ad nulla. (<a href=\"http://example.org/tags/cupidatat\">cupidatat</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Amet do id culpa culpa laboris et laborum in. Culpa quis laboris velit adipisicing sunt est excepteur Lorem elit dolore non eiusmod ipsum. Aute eiusmod quis in duis consectetur nulla commodo. (<a href=\"http://example.org/tags/laboris\">laboris</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Ad enim proident pariatur dolor aute sunt dolor id est incididunt. Culpa id irure enim do incididunt proident id tempor sint incididunt. Pariatur laborum exercitation elit magna do anim nisi dolore in irure. (<a href=\"http://example.org/tags/nulla\">nulla</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Eiusmod velit dolor laboris est. Aute anim laboris ut mollit. Duis cupidatat ullamco et Lorem aliqua sit occaecat minim. Deserunt ea aliqua ea non voluptate duis elit exercitation culpa incididunt aliquip eiusmod magna. Consectetur cillum culpa sit irure irure aliquip aliquip enim consectetur reprehenderit do. (<a href=\"http://example.org/tags/anim\">anim</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Aliqua velit deserunt occaecat cillum eu mollit. Eu magna anim commodo cupidatat nostrud laboris ad deserunt est pariatur duis commodo Lorem. Et deserunt sint tempor labore Lorem deserunt culpa qui. Nostrud consectetur exercitation voluptate minim ex eiusmod labore excepteur. Duis minim eu cillum veniam id ea irure anim veniam dolor. Mollit commodo id velit consectetur non fugiat eiusmod. (<a href=\"http://example.org/tags/cupidatat\">cupidatat</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Adipisicing incididunt deserunt aliquip aliquip. Ad aute enim ipsum do eiusmod. Dolor aliquip aliquip dolor ea deserunt. Quis voluptate laboris dolore dolore irure eu velit non adipisicing. (<a href=\"http://example.org/tags/laboris\">laboris</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Ea duis dolor dolore commodo esse aliqua et Lorem in fugiat irure magna velit. Minim in nostrud exercitation eu sint aute et culpa elit nostrud cillum reprehenderit fugiat ullamco. Anim velit amet deserunt dolor id cupidatat sit sint in pariatur nisi ad. Incididunt labore labore aliqua anim cillum velit dolore do exercitation. Ea dolor et eu aliqua reprehenderit ad cupidatat amet dolore officia elit cillum amet. (<a href=\"http://example.org/tags/irure\">irure</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Elit reprehenderit in excepteur cupidatat veniam incididunt proident qui ullamco pariatur veniam culpa duis adipisicing. Labore cupidatat do sit irure ut esse laboris. Exercitation dolor sint consequat eu sunt ea amet. In consequat nisi mollit do dolore labore proident eu eu Lorem in. (<a href=\"http://example.org/tags/laboris\">laboris</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Consequat dolore fugiat tempor labore laborum do id. Anim dolor veniam ex esse Lorem consequat deserunt. Minim fugiat aliquip est veniam. Deserunt velit sunt voluptate quis tempor sint. (<a href=\"http://example.org/tags/ullamco\">ullamco</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Proident dolor et commodo in excepteur duis. Et culpa aliquip dolor ipsum quis culpa. Elit sit velit irure nisi sit velit eu sit non cillum ipsum ea incididunt id. (<a href=\"http://example.org/tags/culpa\">culpa</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Minim adipisicing aliquip sint occaecat eiusmod. Non cupidatat elit eu nulla aliqua. Lorem pariatur magna esse deserunt ullamco adipisicing nisi commodo minim ipsum. Deserunt ad exercitation ea consectetur sint commodo occaecat nostrud incididunt aute. Consectetur amet cillum consectetur nisi consequat sit ipsum id in laboris. (<a href=\"http://example.org/tags/voluptate\">voluptate</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Aute tempor non et consectetur. Anim aliqua laboris labore nostrud magna pariatur occaecat non commodo commodo qui tempor cupidatat amet. Deserunt sunt ad laborum id. Officia officia sunt nulla qui amet amet ipsum commodo. Fugiat consequat ea id nisi aliquip commodo aliqua ipsum do ullamco enim dolor nostrud. (<a href=\"http://example.org/tags/sit\">sit</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Minim veniam officia ullamco et nostrud elit anim duis elit aliquip qui fugiat. Dolore ea fugiat dolore anim eiusmod sint aliquip enim sint ipsum sunt qui. Culpa nulla cillum nostrud culpa nulla enim incididunt. Nisi deserunt anim ullamco deserunt id eiusmod ex labore. Dolor do ullamco irure nulla sit elit officia officia mollit est excepteur consectetur ex ullamco. (<a href=\"http://example.org/tags/enim\">enim</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Culpa non velit labore sint ex eiusmod officia ut eu elit nulla. Minim sint exercitation dolore non minim reprehenderit sunt proident. Nostrud ea velit laborum Lorem sint ullamco mollit. Ad in ullamco sit mollit dolor labore minim incididunt occaecat amet deserunt do. Nulla velit consequat do sunt minim sit. Commodo enim nostrud cupidatat officia eiusmod excepteur nisi irure minim elit reprehenderit est laboris. Voluptate enim sint ut cupidatat quis esse. (<a href=\"http://example.org/tags/magna\">magna</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Et incididunt eu fugiat et ullamco ipsum officia deserunt. Sit anim deserunt reprehenderit amet sit est occaecat et nisi velit veniam. Est eiusmod quis cupidatat est voluptate velit ad ad eiusmod consectetur quis aliquip adipisicing. (<a href=\"http://example.org/tags/nostrud\">nostrud</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Dolor ea nisi Lorem reprehenderit et nostrud veniam dolore excepteur velit culpa sint anim. Dolor Lorem reprehenderit pariatur nostrud. Et eiusmod aliquip cupidatat cillum officia. Amet sit consequat sunt ut labore. Est excepteur Lorem officia quis magna aliqua ad. Exercitation eu velit officia magna incididunt et voluptate enim. Magna ut enim veniam veniam. (<a href=\"http://example.org/tags/consectetur\">consectetur</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Excepteur culpa consectetur culpa cupidatat ipsum nulla mollit dolore nisi duis Lorem id veniam velit. Officia aute ex mollit mollit cillum esse occaecat laboris id duis et esse. Adipisicing deserunt consequat mollit deserunt. Ad anim velit nisi et do incididunt adipisicing amet non. Enim nisi esse pariatur velit pariatur do exercitation proident. Labore duis occaecat officia fugiat esse aute pariatur laboris incididunt aliqua id nisi Lorem. Mollit fugiat non deserunt Lorem consequat anim. (<a href=\"http://example.org/tags/minim\">minim</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Lorem voluptate est consectetur anim labore mollit et aliqua veniam do ut. Eiusmod irure eu nulla id ad do. Sit deserunt aliqua exercitation ullamco officia nulla elit magna in. Velit in irure do dolore. Lorem labore eu do culpa deserunt deserunt. Sit ad exercitation cillum tempor quis deserunt. (<a href=\"http://example.org/tags/excepteur\">excepteur</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />", "Laboris nisi laborum consequat mollit culpa ad irure irure sint dolore laborum excepteur. Ullamco adipisicing sunt aliqua voluptate officia minim laboris labore deserunt anim laboris. Culpa pariatur cupidatat fugiat labore aute voluptate est enim minim ut exercitation deserunt. Proident incididunt veniam deserunt ipsum enim. (<a href=\"http://example.org/tags/cupidatat\">cupidatat</a>) <img src=\"http://cdn.example.org/rss/image.png\" alt=\"\" width=\"1\" height=\"1\" />" };
    QString plainDescriptions[] = { "Et aliquip et amet duis aliquip Lorem mollit velit amet pariatur. Reprehenderit incididunt occaecat ex nostrud amet sit nulla tempor nulla sit consequat enim. Pariatur culpa ad commodo reprehenderit ipsum amet consectetur officia et. Sint incididunt laborum ad ea id dolore ex do labore aliqua magna. Deserunt aliqua duis sunt laborum nisi aute deserunt officia elit sunt tempor ex velit et. Non dolore commodo commodo ex nostrud incididunt. Consequat est exercitation id tempor nostrud esse enim ea laboris aute commodo eu laborum. (eiusmod)", "Ea exercitation laborum sunt dolore aliquip irure reprehenderit duis ex nulla cupidatat reprehenderit sunt. Ullamco deserunt aute officia eiusmod amet nulla labore culpa ullamco cillum aute ullamco quis est. Elit ullamco duis ipsum culpa eu deserunt et deserunt ea in est sint sint irure. Excepteur culpa sint nulla est labore aute ut reprehenderit ex ullamco nisi aliquip. Minim proident aliquip aute quis mollit id. Occaecat sit ea duis magna anim mollit nulla sit proident tempor adipisicing officia. Commodo duis cillum et Lorem incididunt tempor eu. (ipsum)", "Ut Lorem nostrud duis sit nulla sint. Labore Lorem ullamco nostrud sint laborum incididunt velit adipisicing. Eiusmod sunt esse qui nulla ullamco reprehenderit commodo ex nostrud aliquip ipsum esse laboris reprehenderit. (tempor)", "Ipsum Lorem nulla deserunt non ex deserunt cupidatat nostrud aliqua incididunt laborum amet ut excepteur. Ea labore magna labore incididunt eu cillum aliquip do do. Duis quis laborum ea incididunt non. (ea)", "Nisi quis tempor et consequat eu magna ipsum quis nostrud in fugiat cupidatat consequat. Cupidatat non adipisicing enim est deserunt ullamco ea consectetur ipsum ea aute. Mollit eiusmod dolore cillum enim. Anim ipsum aute est sit mollit non commodo irure laboris consectetur. Esse qui consectetur voluptate esse id ut et excepteur non commodo pariatur labore amet incididunt. Lorem consequat qui Lorem enim officia ea mollit ut mollit. Adipisicing duis et id sint aliqua sint. (id)", "Deserunt id dolor nulla ex voluptate ad ex culpa. Ea magna est nulla eu voluptate. Nisi consectetur ea fugiat officia elit eiusmod non. Ipsum eiusmod officia sunt voluptate fugiat irure amet. Tempor nisi consectetur cupidatat reprehenderit ullamco. Occaecat fugiat irure minim enim consequat minim culpa. Ut excepteur enim veniam laborum irure. (labore)", "Aute adipisicing adipisicing ex amet elit laboris sunt dolor enim est duis magna excepteur aute. Tempor tempor ad non commodo anim id ea. Minim irure qui dolor veniam nulla ex reprehenderit cillum exercitation consequat quis laboris anim. (nulla)", "Aliquip aute irure eiusmod deserunt pariatur occaecat. Ex eiusmod elit aliqua id officia ipsum deserunt duis incididunt enim non consectetur proident do. Ut eu pariatur consectetur mollit. (nostrud)", "Enim excepteur tempor Lorem duis anim nulla irure. Officia nulla non culpa enim do ut occaecat eu minim dolore laborum reprehenderit consequat occaecat. Et quis do adipisicing dolore sit aute. In deserunt laboris qui nostrud consequat esse. Non enim velit ipsum non laboris esse do duis eiusmod veniam voluptate. Pariatur tempor occaecat elit qui reprehenderit aute ullamco ex nulla. Ex sint sint nostrud excepteur aliqua anim cillum id ipsum Lorem sint et. (consectetur)", "Aute ex consectetur ex duis. Incididunt incididunt est eu cillum velit sint incididunt nulla officia irure occaecat ea deserunt eiusmod. Ut ea tempor ex sint reprehenderit. Eiusmod cupidatat officia dolor proident. (exercitation)", "Id officia qui id non enim incididunt. Esse duis excepteur laboris voluptate cillum. Nisi est anim laboris voluptate consequat cupidatat pariatur nulla esse. Sit officia est irure incididunt. (dolore)", "Duis mollit cupidatat minim et commodo dolor in qui magna dolore. Occaecat duis officia ut labore ex mollit Lorem laborum qui deserunt eiusmod. Minim quis nulla non cupidatat dolore ea ex officia in magna reprehenderit proident non excepteur. Reprehenderit dolor sit sint est id cillum consectetur Lorem laboris anim mollit. (fugiat)", "Est nulla eu occaecat incididunt deserunt. Nulla in eu consectetur amet minim sint in ullamco non esse. Ullamco sunt consequat ad culpa do minim ut quis veniam ullamco nulla. Lorem pariatur sint irure aliqua est exercitation elit amet. Minim mollit cillum consequat consequat eu ex. Cillum ad sit anim sit nulla dolor esse ea est. Quis officia consectetur eiusmod exercitation duis eiusmod mollit consectetur ullamco aliqua non mollit mollit fugiat. (est)", "Do laborum laboris cupidatat consectetur mollit. Lorem magna anim irure irure officia culpa sunt exercitation irure consequat. Nisi tempor fugiat et pariatur qui est ullamco amet consequat incididunt duis. Qui consectetur dolore ex nulla ad fugiat pariatur ipsum occaecat est Lorem laboris. (laboris)", "In tempor ea nostrud excepteur cillum magna eu. Ad minim occaecat eu cillum ea irure dolore est aliquip quis. Cillum est cupidatat id nostrud exercitation qui in ullamco nulla eiusmod aliquip. Aute nostrud nostrud ad sint ex sit quis qui deserunt incididunt pariatur dolore reprehenderit voluptate. Ad id amet sunt culpa sint laborum proident sint. Tempor sunt qui anim ut. (reprehenderit)", "Ex proident anim elit labore sint ea dolor ea voluptate duis eu pariatur velit. Fugiat eu eiusmod dolore labore aliquip irure officia. Elit labore sint excepteur commodo veniam in ullamco commodo aliqua sint dolor ullamco et. Laboris dolore fugiat pariatur sint duis ipsum velit mollit. Aute sunt enim exercitation elit quis exercitation. Est voluptate voluptate est nisi reprehenderit ea. Sunt enim exercitation reprehenderit labore est veniam excepteur occaecat fugiat incididunt est aute. (ipsum)", "Commodo dolore mollit velit sunt adipisicing officia. Ut culpa aliqua ipsum cupidatat dolor consequat. Labore laboris velit officia est aliquip. Consequat esse amet laborum exercitation dolor consectetur non sunt consectetur cillum tempor laboris. Cupidatat enim eiusmod culpa qui ad est aliqua laboris. Sint adipisicing et proident sunt enim excepteur cillum fugiat culpa. (ipsum)", "Labore esse esse nisi adipisicing sit occaecat exercitation. Cillum sint excepteur ad non ex consectetur. In irure qui magna velit non. Do sunt magna ipsum anim quis culpa cillum. Incididunt ipsum ad deserunt esse et aliquip aute nostrud tempor in eiusmod quis. Eiusmod voluptate magna commodo elit anim. Irure ut dolor labore ea minim irure deserunt esse. (culpa)", "Esse irure mollit elit tempor duis eiusmod irure laborum in ad culpa reprehenderit id Lorem. Aute nisi eiusmod culpa sunt esse. Deserunt duis ea ut minim commodo duis officia aliqua veniam ex. Nulla consequat minim irure elit. Sit laboris magna minim ipsum. Tempor aute cillum ut dolor reprehenderit aute reprehenderit occaecat commodo cillum duis. Minim sit et nisi sunt dolore sunt duis incididunt consectetur quis sint consequat. (veniam)", "Lorem id est dolore ea amet. Eiusmod esse occaecat deserunt mollit aliqua veniam. Incididunt ex quis qui in proident amet magna commodo id voluptate duis eu dolore proident. Anim dolore voluptate minim minim veniam consectetur aliquip enim. Labore do proident non aute velit consequat consectetur in ipsum id id incididunt cupidatat adipisicing. (ut)", "Veniam nisi laboris et aute veniam aliquip elit anim commodo nisi. Tempor magna sunt deserunt veniam aliquip nisi amet magna. Cupidatat Lorem excepteur mollit sunt veniam voluptate duis et ipsum deserunt esse reprehenderit. (quis)", "Fugiat fugiat eu mollit aliqua culpa nostrud deserunt irure officia est culpa duis Lorem veniam. Elit Lorem tempor enim Lorem adipisicing. Qui eu culpa dolor eiusmod consequat incididunt ullamco dolor ad nulla. (cupidatat)", "Amet do id culpa culpa laboris et laborum in. Culpa quis laboris velit adipisicing sunt est excepteur Lorem elit dolore non eiusmod ipsum. Aute eiusmod quis in duis consectetur nulla commodo. (laboris)", "Ad enim proident pariatur dolor aute sunt dolor id est incididunt. Culpa id irure enim do incididunt proident id tempor sint incididunt. Pariatur laborum exercitation elit magna do anim nisi dolore in irure. (nulla)", "Eiusmod velit dolor laboris est. Aute anim laboris ut mollit. Duis cupidatat ullamco et Lorem aliqua sit occaecat minim. Deserunt ea aliqua ea non voluptate duis elit exercitation culpa incididunt aliquip eiusmod magna. Consectetur cillum culpa sit irure irure aliquip aliquip enim consectetur reprehenderit do. (anim)", "Aliqua velit deserunt occaecat cillum eu mollit. Eu magna anim commodo cupidatat nostrud laboris ad deserunt est pariatur duis commodo Lorem. Et deserunt sint tempor labore Lorem deserunt culpa qui. Nostrud consectetur exercitation voluptate minim ex eiusmod labore excepteur. Duis minim eu cillum veniam id ea irure anim veniam dolor. Mollit commodo id velit consectetur non fugiat eiusmod. (cupidatat)", "Adipisicing incididunt deserunt aliquip aliquip. Ad aute enim ipsum do eiusmod. Dolor aliquip aliquip dolor ea deserunt. Quis voluptate laboris dolore dolore irure eu velit non adipisicing. (laboris)", "Ea duis dolor dolore commodo esse aliqua et Lorem in fugiat irure magna velit. Minim in nostrud exercitation eu sint aute et culpa elit nostrud cillum reprehenderit fugiat ullamco. Anim velit amet deserunt dolor id cupidatat sit sint in pariatur nisi ad. Incididunt labore labore aliqua anim cillum velit dolore do exercitation. Ea dolor et eu aliqua reprehenderit ad cupidatat amet dolore officia elit cillum amet. (irure)", "Elit reprehenderit in excepteur cupidatat veniam incididunt proident qui ullamco pariatur veniam culpa duis adipisicing. Labore cupidatat do sit irure ut esse laboris. Exercitation dolor sint consequat eu sunt ea amet. In consequat nisi mollit do dolore labore proident eu eu Lorem in. (laboris)", "Consequat dolore fugiat tempor labore laborum do id. Anim dolor veniam ex esse Lorem consequat deserunt. Minim fugiat aliquip est veniam. Deserunt velit sunt voluptate quis tempor sint. (ullamco)", "Proident dolor et commodo in excepteur duis. Et culpa aliquip dolor ipsum quis culpa. Elit sit velit irure nisi sit velit eu sit non cillum ipsum ea incididunt id. (culpa)", "Minim adipisicing aliquip sint occaecat eiusmod. Non cupidatat elit eu nulla aliqua. Lorem pariatur magna esse deserunt ullamco adipisicing nisi commodo minim ipsum. Deserunt ad exercitation ea consectetur sint commodo occaecat nostrud incididunt aute. Consectetur amet cillum consectetur nisi consequat sit ipsum id in laboris. (voluptate)", "Aute tempor non et consectetur. Anim aliqua laboris labore nostrud magna pariatur occaecat non commodo commodo qui tempor cupidatat amet. Deserunt sunt ad laborum id. Officia officia sunt nulla qui amet amet ipsum commodo. Fugiat consequat ea id nisi aliquip commodo aliqua ipsum do ullamco enim dolor nostrud. (sit)", "Minim veniam officia ullamco et nostrud elit anim duis elit aliquip qui fugiat. Dolore ea fugiat dolore anim eiusmod sint aliquip enim sint ipsum sunt qui. Culpa nulla cillum nostrud culpa nulla enim incididunt. Nisi deserunt anim ullamco deserunt id eiusmod ex labore. Dolor do ullamco irure nulla sit elit officia officia mollit est excepteur consectetur ex ullamco. (enim)", "Culpa non velit labore sint ex eiusmod officia ut eu elit nulla. Minim sint exercitation dolore non minim reprehenderit sunt proident. Nostrud ea velit laborum Lorem sint ullamco mollit. Ad in ullamco sit mollit dolor labore minim incididunt occaecat amet deserunt do. Nulla velit consequat do sunt minim sit. Commodo enim nostrud cupidatat officia eiusmod excepteur nisi irure minim elit reprehenderit est laboris. Voluptate enim sint ut cupidatat quis esse. (magna)", "Et incididunt eu fugiat et ullamco ipsum officia deserunt. Sit anim deserunt reprehenderit amet sit est occaecat et nisi velit veniam. Est eiusmod quis cupidatat est voluptate velit ad ad eiusmod consectetur quis aliquip adipisicing. (nostrud)", "Dolor ea nisi Lorem reprehenderit et nostrud veniam dolore excepteur velit culpa sint anim. Dolor Lorem reprehenderit pariatur nostrud. Et eiusmod aliquip cupidatat cillum officia. Amet sit consequat sunt ut labore. Est excepteur Lorem officia quis magna aliqua ad. Exercitation eu velit officia magna incididunt et voluptate enim. Magna ut enim veniam veniam. (consectetur)", "Excepteur culpa consectetur culpa cupidatat ipsum nulla mollit dolore nisi duis Lorem id veniam velit. Officia aute ex mollit mollit cillum esse occaecat laboris id duis et esse. Adipisicing deserunt consequat mollit deserunt. Ad anim velit nisi et do incididunt adipisicing amet non. Enim nisi esse pariatur velit pariatur do exercitation proident. Labore duis occaecat officia fugiat esse aute pariatur laboris incididunt aliqua id nisi Lorem. Mollit fugiat non deserunt Lorem consequat anim. (minim)", "Lorem voluptate est consectetur anim labore mollit et aliqua veniam do ut. Eiusmod irure eu nulla id ad do. Sit deserunt aliqua exercitation ullamco officia nulla elit magna in. Velit in irure do dolore. Lorem labore eu do culpa deserunt deserunt. Sit ad exercitation cillum tempor quis deserunt. (excepteur)", "Laboris nisi laborum consequat mollit culpa ad irure irure sint dolore laborum excepteur. Ullamco adipisicing sunt aliqua voluptate officia minim laboris labore deserunt anim laboris. Culpa pariatur cupidatat fugiat labore aute voluptate est enim minim ut exercitation deserunt. Proident incididunt veniam deserunt ipsum enim. (cupidatat)" };
    int index = 0;

    foreach (VNTRSSItem* rssItem, rssChannel->getRSSItems()) {
        QCOMPARE(rssItem->getDescription(), descriptions[index]);
        QCOMPARE(rssItem->getPlainDescription(), plainDescriptions[index++]);
    }
}

void UnitTests::testAtomSiteFooDate() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("atom-site-foo.xml");
    QCOMPARE(rssChannel->getDate(), this->getSimpleDateFormatAtom("2014-11-1420:01:34"));
}

void UnitTests::testAtomSiteFooLink() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("atom-site-foo.xml");
    QCOMPARE(rssChannel->getLink(), QUrl(""));
}

void UnitTests::testAtomSiteFooImageInternet() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("atom-site-foo.xml");
    QCOMPARE(rssChannel->getImageUrl(), QUrl("http://example.foo/rss_logo.png"));
    QCOMPARE(rssChannel->getImageFileType(), QString("png"));
}

void UnitTests::testAtomSiteFooLanguage() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("atom-site-foo.xml");
    QCOMPARE(rssChannel->getLanguage(), QString("en"));
}

void UnitTests::testAtomSiteFooTitle() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("atom-site-foo.xml");
    QCOMPARE(rssChannel->getTitle(), QString("Foo title"));
    QCOMPARE(rssChannel->getPlainTitle(), QString("Foo title"));
}

void UnitTests::testAtomSiteFooDescription() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("atom-site-foo.xml");
    QCOMPARE(rssChannel->getDescription(), QString("Foo description"));
    QCOMPARE(rssChannel->getPlainDescription(), QString("Foo description"));
}

void UnitTests::testAtomSiteFooItemSize() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("atom-site-foo.xml");
    QList<VNTRSSItem*> rssItems = rssChannel->getRSSItems();
    QCOMPARE(rssItems.size(), 108);
}

void UnitTests::testAtomSiteFooItemLink() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("atom-site-foo.xml");
    QString links[] = { "http://www.example.foo/rss/b1b7f9f5-3dc1.html", "http://www.example.foo/rss/8e4e6974-3e38.html", "http://www.example.foo/rss/44cf6563-87c0.html", "http://www.example.foo/rss/3d2e8623-d97c.html", "http://www.example.foo/rss/ddaa1f44-9ada.html", "http://www.example.foo/rss/f37789dc-f0c9.html", "http://www.example.foo/rss/3cfe62c7-0d63.html", "http://www.example.foo/rss/26403a97-9dc9.html", "http://www.example.foo/rss/4d5a3ff2-8e78.html", "http://www.example.foo/rss/e31a31c9-d41f.html", "http://www.example.foo/rss/8b8f4df4-1e32.html", "http://www.example.foo/rss/215c2838-bed1.html", "http://www.example.foo/rss/b8effcba-2366.html", "http://www.example.foo/rss/1c00cd87-d232.html", "http://www.example.foo/rss/2653cc77-50f7.html", "http://www.example.foo/rss/fff383fe-280d.html", "http://www.example.foo/rss/c4ddb6e6-2d8e.html", "http://www.example.foo/rss/ce407232-5769.html", "http://www.example.foo/rss/ed6741a0-21f3.html", "http://www.example.foo/rss/b4cad52a-43e6.html", "http://www.example.foo/rss/1c3c6b75-720b.html", "http://www.example.foo/rss/0ba04430-8975.html", "http://www.example.foo/rss/72b71e92-6759.html", "http://www.example.foo/rss/7c6dd83b-08f7.html", "http://www.example.foo/rss/703b30d8-1bc4.html", "http://www.example.foo/rss/33bfb636-0f86.html", "http://www.example.foo/rss/5a2ed711-ac64.html", "http://www.example.foo/rss/714129e7-66f4.html", "http://www.example.foo/rss/292ceda8-da29.html", "http://www.example.foo/rss/d2a5f687-09a8.html", "http://www.example.foo/rss/1a9a7a1f-361d.html", "http://www.example.foo/rss/65443819-e826.html", "http://www.example.foo/rss/5256715b-66f4.html", "http://www.example.foo/rss/2000bb60-a40c.html", "http://www.example.foo/rss/df0a9723-a6fa.html", "http://www.example.foo/rss/e5f67757-4215.html", "http://www.example.foo/rss/2d1aa385-41c2.html", "http://www.example.foo/rss/87a05dec-fb5d.html", "http://www.example.foo/rss/0cca2171-c1fc.html", "http://www.example.foo/rss/6c108d80-6aa1.html", "http://www.example.foo/rss/8d20e49e-8774.html", "http://www.example.foo/rss/f6d8bcce-1950.html", "http://www.example.foo/rss/8d5d5012-134c.html", "http://www.example.foo/rss/e24961e1-570b.html", "http://www.example.foo/rss/5d5a13ed-0248.html", "http://www.example.foo/rss/d449822c-b6c1.html", "http://www.example.foo/rss/0ccefb27-7206.html", "http://www.example.foo/rss/0cae0a2a-086a.html", "http://www.example.foo/rss/46e71941-6d51.html", "http://www.example.foo/rss/eae7e2a9-fde6.html", "http://www.example.foo/rss/72f5d908-2e51.html", "http://www.example.foo/rss/05a07795-b696.html", "http://www.example.foo/rss/0af18667-3e3e.html", "http://www.example.foo/rss/c1800eb4-0203.html", "http://www.example.foo/rss/8a36ac98-76c5.html", "http://www.example.foo/rss/956a19af-38c2.html", "http://www.example.foo/rss/cc9bb606-182e.html", "http://www.example.foo/rss/04db27e4-c100.html", "http://www.example.foo/rss/c9611a2a-20aa.html", "http://www.example.foo/rss/43d7bbb7-a6db.html", "http://www.example.foo/rss/c9fe60ce-5c4c.html", "http://www.example.foo/rss/01f1d999-691c.html", "http://www.example.foo/rss/d9251920-2c55.html", "http://www.example.foo/rss/021baca6-5557.html", "http://www.example.foo/rss/10ba8595-bc52.html", "http://www.example.foo/rss/6a1897dc-15ce.html", "http://www.example.foo/rss/affa4fd6-9e46.html", "http://www.example.foo/rss/c0cd16fd-ec77.html", "http://www.example.foo/rss/0d269d12-1800.html", "http://www.example.foo/rss/afebab35-facc.html", "http://www.example.foo/rss/8f1b3cd2-a821.html", "http://www.example.foo/rss/bb5893a2-8a7b.html", "http://www.example.foo/rss/56da9b03-b71c.html", "http://www.example.foo/rss/25a1029a-9c5f.html", "http://www.example.foo/rss/6ec7f544-e886.html", "http://www.example.foo/rss/9988f998-cd4a.html", "http://www.example.foo/rss/abfc573a-5a07.html", "http://www.example.foo/rss/560d6b66-36f5.html", "http://www.example.foo/rss/75b62e9c-f6d5.html", "http://www.example.foo/rss/393f97db-fc65.html", "http://www.example.foo/rss/f21807ba-2a3a.html", "http://www.example.foo/rss/3a131641-a4fe.html", "http://www.example.foo/rss/4136a904-67bb.html", "http://www.example.foo/rss/9d19f296-e174.html", "http://www.example.foo/rss/6d962cb8-5e3a.html", "http://www.example.foo/rss/2291331b-8fda.html", "http://www.example.foo/rss/55d9db66-d53c.html", "http://www.example.foo/rss/2c457e7a-8a0b.html", "http://www.example.foo/rss/3e37aa29-dff3.html", "http://www.example.foo/rss/b17c87e4-0133.html", "http://www.example.foo/rss/22efbfbd-95a1.html", "http://www.example.foo/rss/d01eae1c-9758.html", "http://www.example.foo/rss/4bc67bcd-ec04.html", "http://www.example.foo/rss/7bca963a-9465.html", "http://www.example.foo/rss/4897a803-332b.html", "http://www.example.foo/rss/249858de-92da.html", "http://www.example.foo/rss/60315f7e-b2c2.html", "http://www.example.foo/rss/8394268e-1168.html", "http://www.example.foo/rss/ab368082-2831.html", "http://www.example.foo/rss/273659a7-872a.html", "http://www.example.foo/rss/1bc150a0-5a7a.html", "http://www.example.foo/rss/9434d46d-7b0f.html", "http://www.example.foo/rss/fb1fb28f-2ed2.html", "http://www.example.foo/rss/192f49fd-6075.html", "http://www.example.foo/rss/f81ebbe1-a4f3.html", "http://www.example.foo/rss/b7245eb6-e5ed.html", "http://www.example.foo/rss/7417bc3a-9bcd.html", "http://www.example.foo/rss/1e9765a5-7097.html" };
    int index = 0;

    foreach (VNTRSSItem* rssItem, rssChannel->getRSSItems()) {
        QCOMPARE(rssItem->getLink(), QUrl(links[index++]));
    }
}

void UnitTests::testAtomSiteFooItemImages() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("atom-site-foo.xml");
    QString images[] = { "http://www.example.foo/image/b1b7f9f5-3dc1.jpg", "http://www.example.foo/image/8e4e6974-3e38.jpg", "http://www.example.foo/image/44cf6563-87c0.jpg", "http://www.example.foo/image/3d2e8623-d97c.jpg", "http://www.example.foo/image/ddaa1f44-9ada.jpg", "http://www.example.foo/image/f37789dc-f0c9.jpg", "http://www.example.foo/image/3cfe62c7-0d63.jpg", "http://www.example.foo/image/26403a97-9dc9.jpg", "http://www.example.foo/image/4d5a3ff2-8e78.jpg", "http://www.example.foo/image/e31a31c9-d41f.jpg", "http://www.example.foo/image/8b8f4df4-1e32.jpg", "http://www.example.foo/image/215c2838-bed1.jpg", "http://www.example.foo/image/b8effcba-2366.jpg", "http://www.example.foo/image/1c00cd87-d232.jpg", "http://www.example.foo/image/2653cc77-50f7.jpg", "http://www.example.foo/image/fff383fe-280d.jpg", "http://www.example.foo/image/c4ddb6e6-2d8e.jpg", "http://www.example.foo/image/ce407232-5769.jpg", "http://www.example.foo/image/ed6741a0-21f3.jpg", "http://www.example.foo/image/b4cad52a-43e6.jpg", "http://www.example.foo/image/1c3c6b75-720b.jpg", "http://www.example.foo/image/0ba04430-8975.jpg", "http://www.example.foo/image/72b71e92-6759.jpg", "http://www.example.foo/image/7c6dd83b-08f7.jpg", "http://www.example.foo/image/703b30d8-1bc4.jpg", "http://www.example.foo/image/33bfb636-0f86.jpg", "http://www.example.foo/image/5a2ed711-ac64.jpg", "http://www.example.foo/image/714129e7-66f4.jpg", "http://www.example.foo/image/292ceda8-da29.jpg", "http://www.example.foo/image/d2a5f687-09a8.jpg", "http://www.example.foo/image/1a9a7a1f-361d.jpg", "http://www.example.foo/image/65443819-e826.jpg", "http://www.example.foo/image/5256715b-66f4.jpg", "http://www.example.foo/image/2000bb60-a40c.jpg", "http://www.example.foo/image/df0a9723-a6fa.jpg", "http://www.example.foo/image/e5f67757-4215.jpg", "http://www.example.foo/image/2d1aa385-41c2.jpg", "http://www.example.foo/image/87a05dec-fb5d.jpg", "http://www.example.foo/image/0cca2171-c1fc.jpg", "http://www.example.foo/image/6c108d80-6aa1.jpg", "http://www.example.foo/image/8d20e49e-8774.jpg", "http://www.example.foo/image/f6d8bcce-1950.jpg", "http://www.example.foo/image/8d5d5012-134c.jpg", "http://www.example.foo/image/e24961e1-570b.jpg", "http://www.example.foo/image/5d5a13ed-0248.jpg", "http://www.example.foo/image/d449822c-b6c1.jpg", "http://www.example.foo/image/0ccefb27-7206.jpg", "http://www.example.foo/image/0cae0a2a-086a.jpg", "http://www.example.foo/image/46e71941-6d51.jpg", "http://www.example.foo/image/eae7e2a9-fde6.jpg", "http://www.example.foo/image/72f5d908-2e51.jpg", "http://www.example.foo/image/05a07795-b696.jpg", "http://www.example.foo/image/0af18667-3e3e.jpg", "http://www.example.foo/image/c1800eb4-0203.jpg", "http://www.example.foo/image/8a36ac98-76c5.jpg", "http://www.example.foo/image/956a19af-38c2.jpg", "http://www.example.foo/image/cc9bb606-182e.jpg", "http://www.example.foo/image/04db27e4-c100.jpg", "http://www.example.foo/image/c9611a2a-20aa.jpg", "http://www.example.foo/image/43d7bbb7-a6db.jpg", "http://www.example.foo/image/c9fe60ce-5c4c.jpg", "http://www.example.foo/image/01f1d999-691c.jpg", "http://www.example.foo/image/d9251920-2c55.jpg", "http://www.example.foo/image/021baca6-5557.jpg", "http://www.example.foo/image/10ba8595-bc52.jpg", "http://www.example.foo/image/6a1897dc-15ce.jpg", "http://www.example.foo/image/affa4fd6-9e46.jpg", "http://www.example.foo/image/c0cd16fd-ec77.jpg", "http://www.example.foo/image/0d269d12-1800.jpg", "http://www.example.foo/image/afebab35-facc.jpg", "http://www.example.foo/image/8f1b3cd2-a821.jpg", "http://www.example.foo/image/bb5893a2-8a7b.jpg", "http://www.example.foo/image/56da9b03-b71c.jpg", "http://www.example.foo/image/25a1029a-9c5f.jpg", "http://www.example.foo/image/6ec7f544-e886.jpg", "http://www.example.foo/image/9988f998-cd4a.jpg", "http://www.example.foo/image/abfc573a-5a07.jpg", "http://www.example.foo/image/560d6b66-36f5.jpg", "http://www.example.foo/image/75b62e9c-f6d5.jpg", "http://www.example.foo/image/393f97db-fc65.jpg", "http://www.example.foo/image/f21807ba-2a3a.jpg", "http://www.example.foo/image/3a131641-a4fe.jpg", "http://www.example.foo/image/4136a904-67bb.jpg", "http://www.example.foo/image/9d19f296-e174.jpg", "http://www.example.foo/image/6d962cb8-5e3a.jpg", "http://www.example.foo/image/2291331b-8fda.jpg", "http://www.example.foo/image/55d9db66-d53c.jpg", "http://www.example.foo/image/2c457e7a-8a0b.jpg", "http://www.example.foo/image/3e37aa29-dff3.jpg", "http://www.example.foo/image/b17c87e4-0133.jpg", "http://www.example.foo/image/22efbfbd-95a1.jpg", "http://www.example.foo/image/d01eae1c-9758.jpg", "http://www.example.foo/image/4bc67bcd-ec04.jpg", "http://www.example.foo/image/7bca963a-9465.jpg", "http://www.example.foo/image/4897a803-332b.jpg", "http://www.example.foo/image/249858de-92da.jpg", "http://www.example.foo/image/60315f7e-b2c2.jpg", "http://www.example.foo/image/8394268e-1168.jpg", "http://www.example.foo/image/ab368082-2831.jpg", "http://www.example.foo/image/273659a7-872a.jpg", "http://www.example.foo/image/1bc150a0-5a7a.jpg", "http://www.example.foo/image/9434d46d-7b0f.jpg", "http://www.example.foo/image/fb1fb28f-2ed2.jpg", "http://www.example.foo/image/192f49fd-6075.jpg", "http://www.example.foo/image/f81ebbe1-a4f3.jpg", "http://www.example.foo/image/b7245eb6-e5ed.jpg", "http://www.example.foo/image/7417bc3a-9bcd.jpg", "http://www.example.foo/image/1e9765a5-7097.jpg" };
    int index = 0;

    foreach (VNTRSSItem* rssItem, rssChannel->getRSSItems()) {
        QCOMPARE(rssItem->getImageUrl(), QUrl(images[index++]));
        QCOMPARE(rssItem->getImageFileType(), QString("jpg"));
    }
}

void UnitTests::testAtomSiteFooItemDate() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("atom-site-foo.xml");
    QString dates[] = { "2014-11-1419:39:00", "2014-11-1419:13:00", "2014-11-1418:59:00", "2014-11-1418:50:00", "2014-11-1418:06:00", "2014-11-1417:22:00", "2014-11-1417:04:00", "2014-11-1416:50:00", "2014-11-1416:31:00", "2014-11-1416:28:00", "2014-11-1416:06:00", "2014-11-1416:06:00", "2014-11-1416:03:00", "2014-11-1415:19:00", "2014-11-1415:16:00", "2014-11-1415:14:00", "2014-11-1415:11:00", "2014-11-1413:36:00", "2014-11-1413:32:00", "2014-11-1413:27:00", "2014-11-1412:13:00", "2014-11-1412:05:00", "2014-11-1411:56:00", "2014-11-1411:27:00", "2014-11-1411:25:00", "2014-11-1411:21:00", "2014-11-1411:02:00", "2014-11-1410:50:00", "2014-11-1410:23:00", "2014-11-1410:03:00", "2014-11-1409:40:00", "2014-11-1409:37:00", "2014-11-1407:58:00", "2014-11-1405:10:00", "2014-11-1403:53:00", "2014-11-1323:09:00", "2014-11-1321:42:00", "2014-11-1321:29:00", "2014-11-1320:23:00", "2014-11-1318:27:00", "2014-11-1317:20:00", "2014-11-1316:58:00", "2014-11-1316:32:00", "2014-11-1316:29:00", "2014-11-1316:17:00", "2014-11-1315:38:00", "2014-11-1315:38:00", "2014-11-1315:16:00", "2014-11-1315:00:00", "2014-11-1314:00:00", "2014-11-1313:38:00", "2014-11-1313:26:00", "2014-11-1313:04:00", "2014-11-1312:14:00", "2014-11-1312:05:00", "2014-11-1312:01:00", "2014-11-1310:47:00", "2014-11-1223:53:00", "2014-11-1221:54:00", "2014-11-1221:01:00", "2014-11-1220:25:00", "2014-11-1218:54:00", "2014-11-1218:33:00", "2014-11-1217:56:00", "2014-11-1216:22:00", "2014-11-1211:21:00", "2014-11-1119:41:00", "2014-11-1118:44:00", "2014-11-1118:41:00", "2014-11-1118:41:00", "2014-11-1114:44:00", "2014-11-1113:52:00", "2014-11-1113:39:00", "2014-11-1109:41:00", "2014-11-1109:23:00", "2014-11-1100:00:00", "2014-11-1022:26:00", "2014-11-1019:20:00", "2014-11-1016:41:00", "2014-11-1016:20:00", "2014-11-1010:20:00", "2014-11-0916:33:00", "2014-11-0916:29:00", "2014-11-0916:26:00", "2014-11-0913:44:00", "2014-11-0913:09:00", "2014-11-0816:49:00", "2014-11-0800:00:00", "2014-11-0718:46:00", "2014-11-0718:08:00", "2014-11-0707:24:00", "2014-11-0707:20:00", "2014-11-0619:27:00", "2014-11-0615:45:00", "2014-11-0517:20:00", "2014-11-0514:27:00", "2014-11-0400:45:00", "2014-11-0318:03:00", "2014-11-0100:00:00", "2014-08-3111:03:00", "2014-08-2515:17:00", "2014-08-2512:42:00", "2014-08-2509:43:00", "2014-08-2410:13:00", "2014-08-2400:00:00", "2014-08-2400:00:00", "2014-08-1310:22:00", "2014-08-1108:00:00" };
    int index = 0;

    foreach (VNTRSSItem* rssItem, rssChannel->getRSSItems()) {
        QCOMPARE(rssItem->getDate(), this->getSimpleDateFormatAtom(dates[index++]));
    }
}

void UnitTests::testAtomSiteFooItemTitle() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("atom-site-foo.xml");
    QString titles[] = { "aliqua aliquip et proident consequat nostrud", "in esse nulla qui magna est", "quis exercitation laborum ipsum id incididunt", "commodo dolor exercitation laboris id cillum", "fugiat et officia non velit veniam", "do amet dolor sunt ea proident", "ut reprehenderit cupidatat id aliqua consequat", "sit enim quis elit reprehenderit occaecat", "ad ad irure minim incididunt minim", "pariatur commodo eu consectetur officia dolore", "proident in ad qui sit reprehenderit", "elit commodo incididunt ipsum fugiat qui", "commodo labore est officia ipsum voluptate", "cupidatat proident eu dolor commodo duis", "et quis exercitation ad adipisicing labore", "commodo aliquip anim in est irure", "sint in ut aliqua culpa nulla", "ex proident Lorem irure mollit tempor", "deserunt et commodo officia esse labore", "adipisicing reprehenderit nisi aliquip aliqua est", "culpa consequat aute aliqua magna duis", "Lorem voluptate labore veniam do nulla", "officia enim pariatur labore minim aliquip", "enim in ut elit consectetur sunt", "irure ex dolore labore esse culpa", "incididunt dolor ullamco quis ipsum qui", "incididunt occaecat ut proident aliqua occaecat", "nulla consectetur sint ea magna proident", "non commodo nisi officia tempor aliqua", "ex minim aliquip adipisicing duis nisi", "quis ullamco reprehenderit fugiat commodo minim", "consequat fugiat consectetur amet dolor anim", "proident aliqua Lorem nisi enim deserunt", "cupidatat culpa dolor eiusmod ipsum anim", "ad proident proident minim sint ipsum", "aliqua aute quis mollit ea sunt", "consectetur commodo eiusmod occaecat est culpa", "ex et sunt enim incididunt eiusmod", "incididunt laborum anim dolore in ex", "Lorem officia sit ea velit ullamco", "amet incididunt voluptate do ullamco consequat", "consequat excepteur eu deserunt Lorem mollit", "excepteur aliquip ea ad nisi amet", "nisi ex non dolore id amet", "fugiat aliquip ut nisi culpa aliquip", "veniam consectetur labore et esse eiusmod", "reprehenderit mollit nisi fugiat mollit ullamco", "qui laborum minim eu enim commodo", "do eiusmod et nisi eiusmod sint", "culpa magna irure ad tempor tempor", "ut voluptate consequat eiusmod nulla laboris", "dolor officia irure ad exercitation sint", "laborum nisi ex nisi aliqua eu", "in commodo commodo ullamco id ad", "do fugiat deserunt ullamco dolor nulla", "pariatur officia duis laboris do in", "sunt mollit adipisicing magna ea laborum", "anim laborum nisi cillum mollit enim", "laboris laborum minim officia enim laborum", "dolor deserunt voluptate labore eu incididunt", "est officia elit minim culpa deserunt", "velit sit ea qui amet irure", "id adipisicing qui proident elit ipsum", "cupidatat irure ipsum consectetur ut fugiat", "exercitation ipsum proident ea ea amet", "sit mollit anim non et irure", "ad anim ipsum sint ut exercitation", "magna aliquip eiusmod veniam aliquip incididunt", "esse laboris consequat ad aliquip laborum", "culpa labore velit sunt fugiat eu", "nostrud dolore esse in anim pariatur", "anim est amet deserunt do in", "eiusmod reprehenderit pariatur amet eu voluptate", "id excepteur nisi ullamco in incididunt", "irure ullamco velit sit ut elit", "voluptate anim ipsum cillum elit cupidatat", "elit proident excepteur qui laboris quis", "et velit cupidatat aliquip incididunt ea", "non dolor est laboris pariatur enim", "in sit cillum qui cupidatat sint", "incididunt deserunt dolore anim nisi deserunt", "do amet qui quis ut laborum", "non quis magna irure sunt nostrud", "incididunt laborum aliquip consequat quis cupidatat", "fugiat mollit exercitation est pariatur incididunt", "ut ullamco aute dolore sit in", "minim dolore veniam officia ea ea", "aute reprehenderit nisi consectetur dolore ea", "duis ullamco nostrud fugiat dolor qui", "quis aliquip culpa pariatur amet in", "minim dolore cupidatat qui fugiat quis", "ullamco non quis labore labore ex", "nostrud anim et proident incididunt ad", "commodo labore officia in est laborum", "nulla commodo aliqua ullamco ut sunt", "ullamco enim incididunt nisi sit anim", "commodo eiusmod eiusmod magna excepteur veniam", "fugiat nulla nulla fugiat ea consectetur", "dolore tempor amet reprehenderit magna deserunt", "pariatur elit esse officia elit duis", "tempor aute amet ut deserunt ut", "exercitation non id velit deserunt cillum", "ea laborum id ut pariatur exercitation", "labore nulla quis in fugiat voluptate", "do mollit labore incididunt amet enim", "officia anim cupidatat nostrud elit sit", "et dolore magna minim non Lorem", "excepteur reprehenderit qui id commodo ex" };
    QString plainTitles[] = { "aliqua aliquip et proident consequat nostrud", "in esse nulla qui magna est", "quis exercitation laborum ipsum id incididunt", "commodo dolor exercitation laboris id cillum", "fugiat et officia non velit veniam", "do amet dolor sunt ea proident", "ut reprehenderit cupidatat id aliqua consequat", "sit enim quis elit reprehenderit occaecat", "ad ad irure minim incididunt minim", "pariatur commodo eu consectetur officia dolore", "proident in ad qui sit reprehenderit", "elit commodo incididunt ipsum fugiat qui", "commodo labore est officia ipsum voluptate", "cupidatat proident eu dolor commodo duis", "et quis exercitation ad adipisicing labore", "commodo aliquip anim in est irure", "sint in ut aliqua culpa nulla", "ex proident Lorem irure mollit tempor", "deserunt et commodo officia esse labore", "adipisicing reprehenderit nisi aliquip aliqua est", "culpa consequat aute aliqua magna duis", "Lorem voluptate labore veniam do nulla", "officia enim pariatur labore minim aliquip", "enim in ut elit consectetur sunt", "irure ex dolore labore esse culpa", "incididunt dolor ullamco quis ipsum qui", "incididunt occaecat ut proident aliqua occaecat", "nulla consectetur sint ea magna proident", "non commodo nisi officia tempor aliqua", "ex minim aliquip adipisicing duis nisi", "quis ullamco reprehenderit fugiat commodo minim", "consequat fugiat consectetur amet dolor anim", "proident aliqua Lorem nisi enim deserunt", "cupidatat culpa dolor eiusmod ipsum anim", "ad proident proident minim sint ipsum", "aliqua aute quis mollit ea sunt", "consectetur commodo eiusmod occaecat est culpa", "ex et sunt enim incididunt eiusmod", "incididunt laborum anim dolore in ex", "Lorem officia sit ea velit ullamco", "amet incididunt voluptate do ullamco consequat", "consequat excepteur eu deserunt Lorem mollit", "excepteur aliquip ea ad nisi amet", "nisi ex non dolore id amet", "fugiat aliquip ut nisi culpa aliquip", "veniam consectetur labore et esse eiusmod", "reprehenderit mollit nisi fugiat mollit ullamco", "qui laborum minim eu enim commodo", "do eiusmod et nisi eiusmod sint", "culpa magna irure ad tempor tempor", "ut voluptate consequat eiusmod nulla laboris", "dolor officia irure ad exercitation sint", "laborum nisi ex nisi aliqua eu", "in commodo commodo ullamco id ad", "do fugiat deserunt ullamco dolor nulla", "pariatur officia duis laboris do in", "sunt mollit adipisicing magna ea laborum", "anim laborum nisi cillum mollit enim", "laboris laborum minim officia enim laborum", "dolor deserunt voluptate labore eu incididunt", "est officia elit minim culpa deserunt", "velit sit ea qui amet irure", "id adipisicing qui proident elit ipsum", "cupidatat irure ipsum consectetur ut fugiat", "exercitation ipsum proident ea ea amet", "sit mollit anim non et irure", "ad anim ipsum sint ut exercitation", "magna aliquip eiusmod veniam aliquip incididunt", "esse laboris consequat ad aliquip laborum", "culpa labore velit sunt fugiat eu", "nostrud dolore esse in anim pariatur", "anim est amet deserunt do in", "eiusmod reprehenderit pariatur amet eu voluptate", "id excepteur nisi ullamco in incididunt", "irure ullamco velit sit ut elit", "voluptate anim ipsum cillum elit cupidatat", "elit proident excepteur qui laboris quis", "et velit cupidatat aliquip incididunt ea", "non dolor est laboris pariatur enim", "in sit cillum qui cupidatat sint", "incididunt deserunt dolore anim nisi deserunt", "do amet qui quis ut laborum", "non quis magna irure sunt nostrud", "incididunt laborum aliquip consequat quis cupidatat", "fugiat mollit exercitation est pariatur incididunt", "ut ullamco aute dolore sit in", "minim dolore veniam officia ea ea", "aute reprehenderit nisi consectetur dolore ea", "duis ullamco nostrud fugiat dolor qui", "quis aliquip culpa pariatur amet in", "minim dolore cupidatat qui fugiat quis", "ullamco non quis labore labore ex", "nostrud anim et proident incididunt ad", "commodo labore officia in est laborum", "nulla commodo aliqua ullamco ut sunt", "ullamco enim incididunt nisi sit anim", "commodo eiusmod eiusmod magna excepteur veniam", "fugiat nulla nulla fugiat ea consectetur", "dolore tempor amet reprehenderit magna deserunt", "pariatur elit esse officia elit duis", "tempor aute amet ut deserunt ut", "exercitation non id velit deserunt cillum", "ea laborum id ut pariatur exercitation", "labore nulla quis in fugiat voluptate", "do mollit labore incididunt amet enim", "officia anim cupidatat nostrud elit sit", "et dolore magna minim non Lorem", "excepteur reprehenderit qui id commodo ex" };
    int index = 0;

    foreach (VNTRSSItem* rssItem, rssChannel->getRSSItems()) {
        QCOMPARE(rssItem->getTitle(), titles[index]);
        QCOMPARE(rssItem->getPlainTitle(), plainTitles[index++]);
    }
}

void UnitTests::testAtomSiteFooItemDescription() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("atom-site-foo.xml");
    QString descriptions[] = { "Pariatur enim nisi laboris enim veniam minim nisi ut. Dolore dolore fugiat eiusmod et ad nostrud voluptate aute laboris consectetur nulla tempor anim. Deserunt anim adipisicing voluptate do elit minim aute officia aliquip proident laborum in.", "Ipsum labore pariatur tempor officia magna nostrud. Duis voluptate magna minim dolor. Adipisicing irure elit irure sunt dolor duis reprehenderit cillum dolore nostrud commodo excepteur exercitation. Occaecat et ipsum occaecat ea aliqua. Eu ullamco incididunt do eu id proident dolore officia cupidatat.", "Quis tempor consequat id reprehenderit irure ea minim elit sint mollit quis ex ex magna. Anim sit id non tempor veniam duis consequat eu nisi. Non ea deserunt nulla enim minim non.", "Adipisicing enim tempor eiusmod incididunt esse minim dolore elit cillum occaecat ad veniam mollit dolor. Consectetur anim est reprehenderit irure sunt reprehenderit. Ea in irure irure do officia tempor sit. Aliquip veniam officia consectetur commodo tempor aute culpa mollit.", "Cillum veniam dolor ut magna cupidatat incididunt magna exercitation fugiat velit irure nostrud. Enim reprehenderit deserunt nulla sint. Eu proident elit reprehenderit Lorem incididunt in duis magna enim dolor.", "Eu velit duis eiusmod qui deserunt laboris proident esse deserunt nostrud mollit mollit. Labore velit sit reprehenderit nisi amet exercitation deserunt nostrud sit labore enim laboris aute sint. Laboris ea aute quis sit duis consectetur sit adipisicing veniam minim duis enim ipsum quis. Eu aute magna ex id ullamco.", "Commodo pariatur ex commodo commodo nostrud Lorem irure ullamco elit anim in dolore ipsum irure. Nulla nisi laboris dolore proident ea non. Lorem sint deserunt commodo exercitation id dolore commodo proident cillum ullamco labore ullamco.", "Excepteur mollit labore labore culpa nostrud irure Lorem eu et. Sit culpa nostrud Lorem id non. Ut veniam ad minim cillum commodo esse laboris eiusmod anim id reprehenderit sunt. Occaecat sit id elit aute dolor enim excepteur ipsum minim tempor veniam.", "Sunt deserunt nostrud do et in id. Id esse non nostrud magna magna magna minim do non incididunt fugiat elit est. Excepteur ullamco nisi deserunt eiusmod ea irure ad id nulla adipisicing reprehenderit mollit. Adipisicing Lorem nulla eu est sit sit. Ipsum tempor duis proident voluptate voluptate magna pariatur velit culpa quis. Aliquip aute in incididunt sint nisi. Veniam labore consectetur excepteur ut excepteur laboris commodo esse pariatur reprehenderit exercitation excepteur.", "Ea nulla laborum mollit voluptate eiusmod mollit. Nulla velit exercitation sint qui Lorem nostrud magna aliqua minim irure Lorem anim laborum. Minim fugiat laboris velit aliquip mollit tempor. Minim pariatur et elit pariatur laboris do id. Commodo est do aute esse esse laboris laborum aliquip aliquip minim.", "Exercitation tempor esse esse nisi veniam. Id aliquip tempor est duis magna. Ad dolor veniam irure elit exercitation quis. Aliquip ea sunt exercitation dolor ullamco enim eiusmod duis. Laboris minim dolore velit labore qui. Consectetur elit elit culpa culpa amet labore mollit ex nisi consequat sit eu sunt.", "Lorem reprehenderit ex velit id velit ut. Veniam sint id voluptate tempor ea mollit. Ad adipisicing ipsum esse esse culpa magna voluptate duis aliquip excepteur deserunt esse dolor. Fugiat non pariatur incididunt eu exercitation irure consectetur cillum reprehenderit. Qui eu est nulla ea. Ullamco enim esse labore proident eu amet magna ut reprehenderit labore nostrud. Dolor magna fugiat deserunt adipisicing laborum ad fugiat laborum reprehenderit.", "Officia esse irure nostrud qui adipisicing do voluptate. Sint irure minim laborum laborum tempor veniam. Cupidatat dolor nulla duis qui et minim laborum mollit cupidatat id ut dolore esse. Ullamco do dolor aliquip cillum fugiat elit nisi excepteur veniam quis nisi sint. Velit laboris do mollit pariatur proident occaecat nulla veniam. Exercitation et ut culpa adipisicing aute quis.", "Amet ad anim aliquip id ullamco voluptate fugiat consectetur irure officia consequat. Officia mollit reprehenderit adipisicing elit. Sunt aliqua do esse ex consectetur.", "Anim in in exercitation do est. Aliquip nulla Lorem elit quis sunt reprehenderit consequat officia Lorem consequat. Officia est officia est consectetur fugiat occaecat nostrud labore incididunt eiusmod duis proident labore sunt. Incididunt aliqua consectetur esse labore.", "Consectetur nisi ipsum labore ad aliquip eiusmod dolore dolore sunt officia proident et proident fugiat. Exercitation amet voluptate tempor aliqua et fugiat dolor nostrud et amet. Irure cupidatat officia dolore elit ad incididunt laboris. Adipisicing cillum eu amet magna. Commodo sunt eu incididunt in.", "Lorem adipisicing Lorem et consequat cupidatat. Labore occaecat tempor sint non nisi aute incididunt. Do nulla sunt ex minim proident.", "Aliquip excepteur ullamco aute velit. Nostrud laborum fugiat dolore aliquip labore deserunt cupidatat culpa ipsum. Consequat non consequat sint quis. Nostrud aliquip enim est amet elit minim pariatur velit do eu ut sit exercitation. Amet amet labore exercitation adipisicing minim. Pariatur occaecat nostrud ea qui ea. Id do in eiusmod id.", "Deserunt magna dolore nulla esse dolore aute sunt nisi cupidatat sit aliquip est. Eu ipsum velit mollit sunt ullamco eiusmod amet irure nostrud. Fugiat tempor enim commodo elit sunt ex amet minim veniam tempor labore commodo sint sunt. Ut elit tempor ipsum laboris.", "Elit do reprehenderit minim irure. Sunt irure laborum ea consequat irure ea anim ut mollit do aliquip anim laboris. Cillum labore esse in est mollit dolor magna reprehenderit elit amet ullamco. Dolor irure mollit ut tempor aute aliquip elit veniam. Ad commodo cillum laborum est excepteur magna aliqua do magna.", "Mollit cupidatat minim cillum eiusmod proident magna enim excepteur. Irure duis anim ad reprehenderit anim ut enim anim duis fugiat. Eu consectetur culpa et voluptate veniam. Pariatur est proident dolore incididunt aute laboris ad enim quis exercitation.", "Labore duis tempor in voluptate fugiat elit. Irure culpa culpa consequat nulla incididunt irure aliquip ut. Amet enim minim id id id officia cillum anim sunt ipsum. Laborum quis ex commodo commodo dolore officia reprehenderit ex velit. Ex aliqua eu velit est deserunt nostrud sunt eiusmod exercitation reprehenderit. Qui culpa incididunt aliqua eu. Ullamco sunt incididunt commodo pariatur proident voluptate excepteur aliquip eu nisi laborum.", "Reprehenderit deserunt aliquip nisi tempor consequat eu ipsum fugiat pariatur. Officia consectetur est veniam magna et pariatur nostrud cillum et amet. Id reprehenderit cupidatat dolore qui aute. Laboris laboris duis fugiat dolor laborum velit fugiat voluptate.", "Ad id culpa irure deserunt tempor Lorem nulla commodo eu enim anim excepteur do aliqua. Labore magna incididunt occaecat mollit aliqua officia tempor eu anim Lorem veniam eiusmod velit id. Irure proident nostrud mollit culpa sit.", "Deserunt ullamco anim esse est. Quis consectetur sit eiusmod eiusmod laboris pariatur pariatur nostrud ex velit velit velit id. Cupidatat aute adipisicing dolor et duis sit tempor sit tempor laboris exercitation.", "Excepteur ea laborum sint id pariatur irure commodo in quis non. Sunt eiusmod do sunt anim quis. Excepteur adipisicing non ipsum Lorem cupidatat culpa ullamco esse anim aliqua et culpa fugiat dolore. Ullamco commodo ullamco esse do in enim voluptate. Esse velit qui eu in qui nostrud ea anim eiusmod commodo anim deserunt minim. Quis cillum sint sit ipsum do ullamco aliqua elit dolor occaecat laboris sit excepteur commodo. Aliqua deserunt dolor occaecat nulla aute incididunt commodo cillum dolor excepteur velit.", "Incididunt cillum duis magna eiusmod adipisicing non. Ex magna sit est ad Lorem anim magna. Laboris veniam id cupidatat proident qui culpa ullamco excepteur. Et irure esse labore exercitation enim.", "Fugiat irure dolor commodo ut magna duis aute est culpa dolor cillum veniam. Eiusmod eu ut ut reprehenderit id dolore id exercitation cillum ipsum. Dolor qui magna aliquip enim est fugiat non consectetur voluptate proident magna et duis. Aliqua voluptate veniam ex officia proident qui officia aute aliquip incididunt.", "Nostrud non ex quis irure. Occaecat commodo consequat reprehenderit ipsum. Esse pariatur commodo sunt consequat esse sint excepteur cillum sunt amet labore. Excepteur esse consequat occaecat aute commodo officia dolor aliquip.", "Excepteur magna nostrud qui ad irure et elit duis. Esse officia dolore ad occaecat incididunt deserunt anim. Officia officia amet magna quis duis pariatur minim et qui esse culpa. Deserunt id consectetur irure id pariatur esse. Nulla et nisi sint reprehenderit et.", "Ipsum nisi est exercitation qui nostrud aliqua sit consequat labore. Dolor qui elit nostrud consectetur labore incididunt laboris excepteur est minim do ut adipisicing est. Irure id et aliquip tempor cillum incididunt quis amet velit officia ea. Ut ex duis est labore adipisicing.", "Mollit cillum ipsum esse mollit Lorem ullamco magna cillum. Nisi cillum incididunt qui duis pariatur consectetur proident. Dolor occaecat dolor ea do excepteur mollit dolore ex excepteur nisi dolore eiusmod. Consectetur et consectetur ut duis nulla proident aliquip veniam sit sit sint officia.", "Ex do qui eiusmod id. Duis sunt sunt in veniam. Culpa quis amet aliqua aute sunt amet. Id mollit elit consectetur fugiat exercitation. Velit proident eiusmod veniam ut commodo enim do culpa velit reprehenderit laborum nostrud cupidatat.", "Amet do ipsum cillum eiusmod ex dolor laboris culpa tempor id excepteur nisi aliquip consectetur. Lorem id culpa nostrud voluptate nisi exercitation. Esse id minim velit est fugiat voluptate nisi tempor adipisicing tempor sit veniam.", "Mollit amet adipisicing sunt proident. Labore dolor dolor nulla ex commodo Lorem eu. Magna exercitation laboris officia consectetur pariatur ipsum ullamco officia sunt mollit minim.", "Do in laborum veniam minim. Minim aliquip ipsum excepteur veniam reprehenderit dolore duis reprehenderit sunt veniam occaecat nostrud consectetur. Dolore labore exercitation mollit proident proident ut ipsum nostrud do mollit veniam mollit culpa sunt. Laborum deserunt enim pariatur ea dolor labore pariatur. Reprehenderit laborum ut minim pariatur.", "Id minim magna ex tempor. Laboris dolore dolor laboris reprehenderit exercitation. Laboris id tempor deserunt dolor minim tempor veniam cillum sit. Cillum adipisicing excepteur quis dolore.", "Magna aute et proident do duis quis consectetur nulla aute. Laboris velit ut est fugiat ullamco. Nostrud nulla quis amet est amet adipisicing qui nostrud. Fugiat in qui nostrud occaecat quis excepteur elit laboris dolor Lorem nostrud. Proident irure laborum proident qui consequat.", "Eu officia consectetur consequat consequat in ullamco est nulla. Est duis quis id minim ipsum sit ea culpa ullamco laboris. Cillum voluptate mollit fugiat culpa esse laborum nostrud ipsum commodo. Magna fugiat adipisicing sunt elit nulla dolore dolore pariatur exercitation ut proident ad nostrud aute. Reprehenderit duis amet esse tempor pariatur dolor esse irure fugiat ipsum. Fugiat do proident cillum velit aute culpa qui laborum nostrud aute dolor aliquip labore labore. Qui aute sit ut do qui occaecat esse aliqua aliquip velit fugiat.", "Aliqua adipisicing excepteur minim minim dolore dolor Lorem magna veniam nulla sunt exercitation. Eiusmod eiusmod non ut ad quis id qui aute eu labore non in. Deserunt do quis nostrud consequat amet ipsum dolor excepteur consectetur excepteur minim tempor cupidatat enim. Magna reprehenderit consectetur ipsum in consectetur culpa excepteur deserunt veniam ullamco veniam.", "Occaecat magna laborum cupidatat sint eu laborum id commodo. Officia eu non irure in nisi labore aliqua excepteur sit tempor deserunt nostrud laboris nostrud. Sint consectetur dolore dolor non deserunt adipisicing occaecat in sint.", "Magna laboris irure nisi sit. Voluptate laboris amet amet ullamco nostrud. Ipsum cupidatat cupidatat consectetur officia ut exercitation excepteur officia ut consequat ea ipsum in anim.", "Culpa duis elit sunt enim do ut et. Velit eu esse voluptate irure dolore sit aliquip aliqua et commodo officia duis irure ullamco. Culpa exercitation reprehenderit magna sit nisi aliquip proident eiusmod officia nostrud elit. Excepteur voluptate officia excepteur mollit ut. Id aliqua officia ullamco id enim officia sint ad duis eiusmod magna. Qui cillum sunt quis non.", "Labore voluptate esse cillum eu incididunt mollit enim commodo adipisicing aliquip. Est labore consectetur culpa duis duis veniam consectetur veniam aliqua culpa commodo fugiat nostrud. Deserunt enim aute velit Lorem voluptate. Non in aute ad minim est deserunt. Laboris amet aliqua esse amet cupidatat ut occaecat pariatur. Eu ad velit nisi excepteur.", "Nulla laborum eiusmod laboris non esse laboris pariatur voluptate non consectetur. Ullamco aute exercitation aute ut ex. Non sit ex irure ipsum excepteur aliqua exercitation. Reprehenderit Lorem tempor id cillum nostrud aliquip nostrud commodo sunt et qui culpa.", "Non magna mollit culpa ullamco magna incididunt officia laboris labore proident quis tempor. Proident consectetur sit sunt esse aliquip irure voluptate velit est pariatur qui. Incididunt ullamco velit esse veniam sunt. Nostrud laborum consectetur sunt ad in amet ullamco mollit officia velit minim ut labore. Lorem incididunt cupidatat ipsum incididunt excepteur cillum laboris culpa proident amet adipisicing ipsum commodo.", "Enim id et duis dolore est. In sunt quis id sit mollit ad labore aliqua excepteur sit consectetur pariatur et. Cupidatat aliqua magna irure culpa ex ut cupidatat tempor tempor aliquip nostrud elit nulla. Ad fugiat non adipisicing aliquip aliquip.", "Commodo aute consequat ullamco nostrud ipsum irure quis. Voluptate exercitation ex aute ad reprehenderit proident aliqua. Adipisicing magna qui non eiusmod ullamco est irure qui ea in sint occaecat. Nisi duis voluptate aliqua magna proident cupidatat sint cupidatat eu et consequat non do. Reprehenderit irure laborum eiusmod consectetur dolore occaecat est elit sunt. Velit quis sint labore veniam.", "Magna aute ut mollit consectetur anim fugiat ut occaecat labore voluptate. Occaecat non nostrud amet aliqua ad cupidatat voluptate id velit. Aute id minim laborum quis eu commodo consectetur cillum. Culpa ex aliquip ipsum reprehenderit ea non. Incididunt occaecat excepteur reprehenderit tempor. Sit enim mollit incididunt aliquip duis elit nulla deserunt pariatur magna eiusmod voluptate ex.", "Consectetur fugiat ut in fugiat in laborum mollit amet pariatur esse. Laboris excepteur nisi nostrud ullamco aute laborum nulla esse. Lorem sunt magna fugiat duis sit incididunt officia incididunt mollit. Incididunt consequat nostrud esse fugiat deserunt dolor est laborum. Aliqua Lorem minim aute dolore enim amet fugiat. Nostrud Lorem veniam veniam irure commodo non duis. Fugiat proident minim sit sint commodo adipisicing mollit magna adipisicing ullamco non fugiat.", "Qui culpa aute laborum elit anim sunt aliqua est aliquip officia et amet. Ex sit consequat ullamco nulla. Ut eiusmod ad nulla commodo eu eiusmod officia enim labore magna elit. Laboris nisi in Lorem commodo elit occaecat sint enim id excepteur. Eiusmod proident duis in sunt quis dolor voluptate exercitation. Reprehenderit Lorem ut veniam do aliquip qui id ad cillum adipisicing esse qui culpa. Aute ad exercitation consectetur labore.", "Ad proident aliqua proident consectetur dolor esse sint ullamco officia sint nostrud adipisicing enim. Elit incididunt consequat occaecat Lorem. Eu labore dolor sunt occaecat velit laboris ad consequat aliquip reprehenderit in. Reprehenderit qui qui incididunt sint dolore eiusmod proident ipsum ullamco duis consequat et. Velit laborum consectetur amet anim elit quis enim dolore labore consequat ad duis sint enim. Dolor officia reprehenderit officia laboris id aute anim elit est ut. Officia ullamco voluptate non laborum commodo aliquip sint ad commodo ullamco fugiat.", "Sit mollit adipisicing ullamco cillum ea irure esse sunt ullamco ea magna. Irure labore sit irure proident non laboris culpa do quis ad veniam quis dolor. Pariatur occaecat sint cupidatat veniam laborum minim excepteur. Id magna duis dolor dolore cupidatat minim anim id veniam. Non qui ut in deserunt non duis cupidatat consequat magna incididunt.", "Minim exercitation proident anim fugiat irure nostrud cillum exercitation ut amet dolore anim. Est eu elit culpa amet nulla pariatur reprehenderit deserunt laborum culpa. Magna reprehenderit cupidatat ut Lorem Lorem veniam qui sunt fugiat non occaecat. Occaecat tempor ad mollit cillum exercitation ut in magna nisi veniam anim et velit ut. Eu tempor labore esse ipsum.", "Consequat deserunt ut laboris aliqua esse ad non amet tempor irure. Elit aliqua mollit ut enim et ipsum reprehenderit do tempor magna sint. Dolor ad officia Lorem fugiat in aliqua aliquip aliqua sit. Aliqua dolore fugiat magna laborum nisi magna mollit quis eiusmod ut id dolore laboris amet.", "Mollit exercitation fugiat laboris incididunt. Commodo laboris reprehenderit aute qui tempor est ex aute eu laborum pariatur sint ut. Incididunt labore in incididunt dolor deserunt. Nostrud est est incididunt ex ex aute irure adipisicing. Ullamco ullamco sunt officia ea Lorem occaecat cupidatat.", "Reprehenderit proident consectetur laborum reprehenderit nulla ut veniam. Et eiusmod excepteur est ut culpa sunt aliqua labore nisi. Quis id ad incididunt sunt consequat id eiusmod id nulla.", "Eiusmod fugiat esse proident laborum eiusmod. Do est mollit sint Lorem enim culpa. Proident fugiat mollit commodo culpa Lorem laboris et aute ullamco ex ut officia eiusmod.", "Non fugiat quis deserunt esse aute minim ipsum proident velit dolore aliquip. Pariatur labore magna incididunt nisi velit adipisicing excepteur do enim. Voluptate nisi labore dolor tempor elit eu labore ea minim eu incididunt irure mollit ut.", "Ad velit reprehenderit consectetur eiusmod minim. Labore excepteur irure est pariatur laborum. In sit quis irure excepteur enim adipisicing ea cillum exercitation laboris. Quis ad non consequat proident laboris commodo cupidatat cupidatat sint excepteur nulla officia occaecat pariatur. Cillum aliqua in ex minim ex quis nostrud commodo commodo esse nostrud. Occaecat culpa qui tempor do magna aliqua id ad.", "Excepteur tempor consequat in reprehenderit laborum cupidatat adipisicing dolor commodo veniam eiusmod. Irure eu elit commodo nulla do adipisicing nulla nulla. Dolore voluptate non laborum occaecat sunt nisi et nostrud amet sit ullamco. Dolor esse duis sit aliquip occaecat ad. Ea consectetur magna sunt quis anim ipsum laboris ad irure velit mollit. Sint tempor ullamco culpa est minim magna pariatur anim. Sit voluptate ad consectetur voluptate dolor sint cillum et ex commodo exercitation anim.", "Enim esse aliquip mollit non magna nulla deserunt ullamco occaecat mollit. Ut non est Lorem mollit pariatur. Elit consectetur labore excepteur do occaecat et sit culpa.", "Et et commodo deserunt exercitation fugiat commodo qui ad veniam minim eu. Veniam magna sunt incididunt magna et dolor elit. Eu adipisicing in duis laborum amet ipsum.", "In exercitation minim velit id occaecat. Non deserunt dolore culpa ad nulla veniam anim id quis dolore. Magna dolor aliquip minim cillum ea irure dolor excepteur sunt esse ad sunt nostrud.", "Eu qui ullamco est ullamco do deserunt occaecat elit commodo velit commodo eiusmod enim ullamco. Consectetur Lorem laboris minim pariatur ipsum eiusmod. Est adipisicing aliquip tempor magna enim ex. Labore magna consectetur pariatur ea dolor sint laborum consequat consequat anim. In laboris aliquip aliqua anim do non tempor est. Commodo non et eu elit labore et elit esse. Voluptate adipisicing esse aute anim dolore proident culpa duis ut.", "Eiusmod sit sit nostrud enim ex sit consequat mollit ad officia quis occaecat adipisicing. Sit dolore ad do adipisicing laborum ipsum deserunt id officia deserunt ea minim ea. Aliquip adipisicing reprehenderit dolore laborum aute do enim anim.", "Voluptate cillum esse quis in tempor enim adipisicing aute amet non et cupidatat. Labore cillum consectetur pariatur culpa. Irure amet proident quis et ex est id duis esse.", "Incididunt duis Lorem Lorem tempor et nisi deserunt aliqua quis nostrud. Anim adipisicing ex eiusmod duis ea laborum sunt magna laboris velit. Non elit Lorem eiusmod nostrud culpa cillum dolore nisi enim eu non. Labore ut adipisicing incididunt exercitation ut occaecat ad tempor culpa. Laboris deserunt ea eu ex eu velit aute ullamco fugiat eu quis adipisicing. Magna dolor excepteur culpa cillum.", "Esse labore est incididunt quis voluptate laborum eu commodo duis. Lorem adipisicing ullamco ex ipsum sunt mollit nisi exercitation. Pariatur id minim ex veniam occaecat. Occaecat adipisicing duis Lorem velit quis anim elit ex velit cupidatat consequat id culpa id. Et tempor ut Lorem ut. Sunt consequat eiusmod adipisicing ad reprehenderit non in laborum veniam occaecat laboris. Nulla sint consectetur duis quis consectetur mollit proident elit reprehenderit.", "Exercitation proident dolor irure id proident mollit aliqua deserunt deserunt esse incididunt irure dolore deserunt. Exercitation irure anim ad proident. Cillum cillum fugiat eiusmod occaecat. Duis deserunt fugiat minim eu et quis qui aliqua occaecat tempor non ea exercitation consequat. Cillum Lorem incididunt ullamco est magna qui irure do minim esse deserunt incididunt est.", "In laborum est deserunt ex proident sint commodo. Proident pariatur sunt aliquip anim Lorem ex. Cillum dolor minim consectetur qui aliqua mollit velit ipsum tempor cillum proident officia. Ex culpa duis magna voluptate velit aliqua.", "Occaecat nulla quis pariatur dolor aute in laboris velit proident ex aute ex quis consectetur. Nostrud cupidatat nostrud incididunt quis proident cillum ex est pariatur nisi elit mollit minim commodo. Lorem magna nisi ex qui ex dolor eu.", "Enim ipsum aliquip pariatur labore dolore voluptate. Esse mollit commodo do nisi enim eiusmod tempor mollit Lorem non labore. Consectetur sit nostrud ex nulla mollit proident officia reprehenderit ipsum incididunt exercitation. Pariatur ullamco velit labore ad ex excepteur commodo qui eiusmod amet fugiat quis excepteur laborum. Incididunt enim exercitation id duis et reprehenderit sit exercitation ullamco consequat aliquip.", "Dolor aliquip ullamco voluptate officia eiusmod amet elit id fugiat. Velit occaecat id officia aliquip deserunt quis. Esse proident in eiusmod ex enim veniam nisi ut aliqua id sunt cupidatat.", "Ex laborum reprehenderit voluptate voluptate eu laboris elit consequat elit. In ut ipsum reprehenderit irure sit anim ea sunt ut sit sunt occaecat. Fugiat laboris nulla adipisicing pariatur ea.", "Magna deserunt officia commodo id laboris incididunt Lorem in esse laborum dolore. Velit est enim mollit in amet occaecat consectetur voluptate tempor. Minim irure exercitation anim ut voluptate culpa sint. Proident sit irure in excepteur nostrud aliquip fugiat culpa amet mollit cupidatat nisi tempor proident.", "Elit laboris aute exercitation ea dolor. Sunt id aliqua laboris enim elit duis irure cillum. Culpa consequat Lorem ea esse magna cillum sint irure dolor tempor.", "Commodo amet nisi mollit laborum aute aliquip cupidatat aute consectetur. Ea consectetur in ex Lorem. Quis non laborum laboris laborum deserunt labore adipisicing eiusmod ipsum anim elit voluptate. Et dolore commodo nulla ullamco veniam commodo exercitation aute veniam anim incididunt ad pariatur. Tempor nostrud est consectetur excepteur. Velit elit ullamco aliquip est aliquip ex qui exercitation labore nostrud.", "Adipisicing fugiat cillum elit anim veniam ut consequat mollit qui mollit in nulla cupidatat commodo. Sit dolor non quis proident aliqua reprehenderit consectetur aute mollit proident reprehenderit. Consectetur mollit sit deserunt fugiat ad aliqua et consectetur dolor est culpa labore. Dolore id dolore laboris quis pariatur dolore in proident nisi irure cupidatat. Voluptate ullamco non enim laboris deserunt ea magna voluptate in eiusmod incididunt veniam. Lorem dolore qui consectetur velit sunt elit adipisicing sint. Ea in cillum incididunt excepteur quis mollit minim minim laborum commodo et minim eu Lorem.", "Cupidatat in mollit laborum incididunt. Cillum dolor aliquip aliquip occaecat elit nisi in duis incididunt officia exercitation ea aliqua duis. Anim qui enim culpa quis cillum. Labore fugiat laborum anim ullamco in ex. Non ex dolore velit ex deserunt sint quis ex cupidatat enim. Commodo ut magna amet enim eu sunt nostrud esse cupidatat excepteur. Sit velit ea velit cupidatat ipsum.", "Dolor laborum cillum do do ex irure laborum minim consectetur culpa aliqua mollit. Sunt Lorem aute Lorem cillum amet. Magna eu ea in et fugiat. Quis cillum elit fugiat culpa qui proident nisi nostrud tempor laboris incididunt. Cupidatat ea incididunt voluptate enim cillum elit.", "Voluptate minim non minim id nostrud est dolor ex qui nostrud aute duis ut. Nulla dolor aliqua consequat ullamco ea. Sunt incididunt tempor qui anim tempor irure exercitation elit proident. Mollit sit quis ut mollit labore ipsum sunt adipisicing voluptate incididunt enim laborum ex eiusmod. Est magna labore quis dolor consequat aliqua ad nisi. Minim velit dolore consectetur excepteur culpa commodo. Id laboris irure labore velit et fugiat nulla.", "Amet sit ipsum eiusmod enim excepteur dolor quis amet laboris eu culpa nulla ad. Ad mollit duis est et fugiat aliqua adipisicing est magna exercitation cillum elit. Dolor aliquip non pariatur esse magna aute mollit proident qui officia. Cupidatat officia nostrud aliqua ex sit veniam sint elit. Lorem ut ea id ad officia esse qui. Exercitation dolore consectetur in consectetur proident eu culpa ad quis officia quis mollit reprehenderit dolore.", "Tempor ullamco labore ipsum elit nisi excepteur eiusmod. Esse reprehenderit fugiat commodo esse Lorem quis laboris nisi aliquip amet labore sit. Anim consectetur nostrud in eiusmod. Consequat sit sint aliqua commodo ex nulla velit laboris reprehenderit proident sit magna consectetur. Ea ex dolor excepteur qui velit ad Lorem commodo nulla culpa nulla id commodo sunt. Ea nulla est enim anim.", "Fugiat consequat consectetur consequat laborum. Nisi nisi amet ex non irure duis sint. Esse magna laboris nostrud laborum aliquip. Ut occaecat Lorem velit eiusmod nulla nostrud aliqua. Ad laboris voluptate dolor nisi dolor non. Anim labore exercitation sint pariatur quis. Laborum labore dolore nostrud adipisicing Lorem.", "Ad occaecat deserunt pariatur laborum ipsum minim. Veniam laboris adipisicing proident magna labore dolore excepteur exercitation Lorem sunt voluptate culpa fugiat tempor. Do amet nostrud aliqua enim do dolore proident ex ipsum laboris nisi dolore aliqua.", "Pariatur sint consequat consequat magna. Elit do esse consequat cupidatat enim sit anim. Incididunt aliquip tempor dolore ullamco et minim esse enim officia fugiat.", "Consequat nulla excepteur anim labore sit labore amet ipsum. Non aliquip sit occaecat laborum cupidatat reprehenderit aute veniam ipsum minim nostrud ea. Cupidatat enim quis deserunt id minim duis. Sit exercitation enim quis id mollit aliqua. Pariatur commodo eu veniam magna enim aliquip velit sit ex mollit cupidatat. Esse id ad proident magna. Ut quis est excepteur duis eiusmod quis elit cupidatat dolore officia veniam excepteur irure consectetur.", "Aute officia et esse consectetur ut labore velit laborum consequat. Eiusmod eu enim occaecat eu enim exercitation qui mollit in excepteur officia exercitation ad. Non quis aute dolor quis elit ad. Voluptate proident ea laboris labore amet. Aute culpa tempor exercitation adipisicing labore qui nisi tempor. Non sunt cillum sint deserunt non enim amet aute laboris consequat veniam magna proident cupidatat. Irure duis adipisicing eu ex exercitation eiusmod.", "Labore ex dolore labore ad sunt. Amet ipsum ex voluptate nostrud cupidatat occaecat occaecat. Ut est consectetur qui aliqua incididunt proident ullamco. Ex elit officia elit anim nostrud eiusmod amet. Aute commodo enim nostrud adipisicing. Dolore sint duis elit nostrud in velit mollit nisi elit.", "Laborum aliqua eu labore eiusmod mollit labore officia. Incididunt culpa ex incididunt ex non cupidatat eiusmod aliquip sunt. Eu veniam ex ipsum sint exercitation laborum non aliquip laborum irure culpa. Eiusmod culpa ipsum ad fugiat Lorem labore non. Aliquip dolor occaecat incididunt enim nostrud id ipsum quis irure exercitation et enim enim. Minim ullamco eiusmod quis adipisicing qui do tempor. Anim ut enim culpa non deserunt proident duis cillum veniam aute ut fugiat velit qui.", "Reprehenderit occaecat ut anim ut magna ut elit labore cillum mollit laborum. Amet magna officia do anim do fugiat dolore et dolore est. In qui incididunt anim occaecat commodo est incididunt sunt minim. Minim laborum aliquip et adipisicing commodo culpa cupidatat id nisi duis. Dolor magna reprehenderit ad eu proident nulla pariatur non.", "Velit culpa ea anim reprehenderit. Lorem laboris pariatur ullamco esse ea nostrud dolor deserunt duis veniam duis nisi. Ex quis ex amet quis in quis ipsum laborum consequat exercitation. Aliquip ad consequat dolor reprehenderit occaecat veniam enim anim ipsum elit commodo.", "Nulla quis consectetur minim non elit irure do aute veniam minim. Deserunt do ipsum do consequat. Anim qui quis ad eiusmod tempor qui irure sint commodo labore. Aliqua aute sit in occaecat.", "Officia sit enim aute adipisicing culpa dolor fugiat cupidatat. Id minim dolor est deserunt fugiat irure pariatur adipisicing aute. Adipisicing officia exercitation exercitation aliquip id. Proident laborum velit labore laborum laboris dolore est proident nisi. Amet occaecat officia ea elit velit. Nisi eiusmod incididunt officia cillum est aliqua ex aliquip elit aliquip esse tempor anim.", "Exercitation quis in elit commodo incididunt pariatur non nisi minim officia anim sunt deserunt. Ex irure commodo officia ad commodo incididunt Lorem. Mollit tempor mollit laborum nulla exercitation nulla incididunt consequat incididunt. Id amet enim id magna enim sint id laboris sint commodo fugiat dolore. Pariatur est mollit in incididunt voluptate.", "Incididunt sit consectetur irure amet. Cillum aliquip reprehenderit aliqua id officia velit culpa irure. Sit mollit quis dolore ex dolore voluptate et Lorem ex commodo. Dolor magna enim enim ullamco ea nulla.", "Culpa esse exercitation incididunt proident tempor ex incididunt laborum anim pariatur amet elit nostrud esse. Sit consequat sint aute nostrud sit sint anim voluptate ipsum non velit. Id quis dolore eiusmod nulla adipisicing et consequat ea consequat dolore reprehenderit.", "Ullamco eiusmod nostrud est commodo nostrud. Amet consequat nisi id proident cupidatat exercitation labore amet eu occaecat officia dolor. Sit esse est ullamco et reprehenderit.", "Adipisicing aliquip dolor aute anim eiusmod aute ut ad voluptate mollit ullamco fugiat nulla. Duis do ex laborum consectetur irure laboris incididunt. Id officia nulla nisi occaecat duis dolore consequat deserunt quis id nulla do id. Occaecat nostrud ea ipsum elit ipsum pariatur. Fugiat incididunt Lorem eu cupidatat reprehenderit cillum dolore reprehenderit laboris ullamco minim. Occaecat voluptate qui non anim minim non ut fugiat velit proident cupidatat cillum.", "Esse nisi veniam deserunt consequat elit sunt anim occaecat. Pariatur consequat irure elit labore laboris labore aute est velit. Cillum aute quis ullamco enim fugiat id sit et occaecat et. Fugiat ut et sit sint cillum in tempor in reprehenderit consequat nostrud anim pariatur. Anim sit aute qui nisi dolore eiusmod enim sint. Incididunt dolor adipisicing velit irure Lorem sunt adipisicing pariatur dolore mollit aliqua pariatur.", "Aute excepteur et cupidatat commodo fugiat non cupidatat consectetur enim pariatur ex. Deserunt deserunt velit minim do ipsum eu sunt magna ad. Veniam dolore elit sint aliqua ex. Et commodo ipsum in exercitation occaecat aliquip enim velit sunt nulla. Reprehenderit do officia quis irure labore pariatur ad voluptate voluptate. Ipsum elit velit minim fugiat laboris non excepteur Lorem amet et Lorem mollit et esse. Minim ullamco aute in quis quis reprehenderit sunt deserunt aliquip excepteur ullamco aliqua sint.", "Non in mollit aute aliqua. Sint laborum adipisicing sit duis elit amet deserunt id magna qui dolor et incididunt. Veniam magna ullamco dolore anim elit ad.", "Nisi officia ad aute ex. Ea deserunt nisi fugiat dolore pariatur fugiat reprehenderit nostrud exercitation. Adipisicing id enim duis laboris nulla ullamco sit dolor incididunt excepteur. Do aute et ex enim mollit magna eu enim. Officia ad ipsum mollit ullamco aliquip proident sint aliqua Lorem nulla. Eu officia qui mollit proident magna cupidatat ad enim.", "Labore ad adipisicing esse ex eu. Minim ut ea laboris elit cupidatat eiusmod. Commodo Lorem esse laborum do dolore cillum cupidatat incididunt culpa nulla qui ea voluptate ad. Veniam ipsum fugiat laborum reprehenderit. Minim ea cillum irure quis amet enim esse ullamco quis ipsum dolor. Laboris non labore laboris qui incididunt ipsum.", "Officia labore minim ullamco qui commodo qui. Lorem consequat amet minim do sit magna duis. Velit commodo nisi in adipisicing nisi voluptate ex enim sunt voluptate ullamco est dolor. Nisi voluptate eiusmod tempor qui occaecat enim est ullamco deserunt. Excepteur exercitation deserunt quis est cupidatat nulla do nostrud. Voluptate magna consectetur adipisicing non eu Lorem aliqua ex anim consequat id fugiat.", "Aliquip anim mollit ut duis labore. Et dolor ipsum dolore anim excepteur ullamco adipisicing laborum quis veniam consectetur nisi incididunt duis. Sit laborum tempor ullamco mollit. Aliqua amet cillum consequat minim duis aute culpa ad dolor proident adipisicing nisi exercitation. Proident voluptate dolore eu velit enim elit magna eu sint consequat ipsum in ad. Dolore ullamco exercitation tempor non consectetur quis pariatur elit est exercitation sit.", "Adipisicing veniam reprehenderit nisi sunt ad ullamco amet labore aliquip in. Quis in id tempor sunt cupidatat ea eiusmod pariatur ut officia id. Proident ea quis eiusmod in qui tempor. Eu quis dolore pariatur ut dolore laborum do enim nostrud irure voluptate proident ullamco dolor." };
    QString plainDescriptions[] = { "Pariatur enim nisi laboris enim veniam minim nisi ut. Dolore dolore fugiat eiusmod et ad nostrud voluptate aute laboris consectetur nulla tempor anim. Deserunt anim adipisicing voluptate do elit minim aute officia aliquip proident laborum in.", "Ipsum labore pariatur tempor officia magna nostrud. Duis voluptate magna minim dolor. Adipisicing irure elit irure sunt dolor duis reprehenderit cillum dolore nostrud commodo excepteur exercitation. Occaecat et ipsum occaecat ea aliqua. Eu ullamco incididunt do eu id proident dolore officia cupidatat.", "Quis tempor consequat id reprehenderit irure ea minim elit sint mollit quis ex ex magna. Anim sit id non tempor veniam duis consequat eu nisi. Non ea deserunt nulla enim minim non.", "Adipisicing enim tempor eiusmod incididunt esse minim dolore elit cillum occaecat ad veniam mollit dolor. Consectetur anim est reprehenderit irure sunt reprehenderit. Ea in irure irure do officia tempor sit. Aliquip veniam officia consectetur commodo tempor aute culpa mollit.", "Cillum veniam dolor ut magna cupidatat incididunt magna exercitation fugiat velit irure nostrud. Enim reprehenderit deserunt nulla sint. Eu proident elit reprehenderit Lorem incididunt in duis magna enim dolor.", "Eu velit duis eiusmod qui deserunt laboris proident esse deserunt nostrud mollit mollit. Labore velit sit reprehenderit nisi amet exercitation deserunt nostrud sit labore enim laboris aute sint. Laboris ea aute quis sit duis consectetur sit adipisicing veniam minim duis enim ipsum quis. Eu aute magna ex id ullamco.", "Commodo pariatur ex commodo commodo nostrud Lorem irure ullamco elit anim in dolore ipsum irure. Nulla nisi laboris dolore proident ea non. Lorem sint deserunt commodo exercitation id dolore commodo proident cillum ullamco labore ullamco.", "Excepteur mollit labore labore culpa nostrud irure Lorem eu et. Sit culpa nostrud Lorem id non. Ut veniam ad minim cillum commodo esse laboris eiusmod anim id reprehenderit sunt. Occaecat sit id elit aute dolor enim excepteur ipsum minim tempor veniam.", "Sunt deserunt nostrud do et in id. Id esse non nostrud magna magna magna minim do non incididunt fugiat elit est. Excepteur ullamco nisi deserunt eiusmod ea irure ad id nulla adipisicing reprehenderit mollit. Adipisicing Lorem nulla eu est sit sit. Ipsum tempor duis proident voluptate voluptate magna pariatur velit culpa quis. Aliquip aute in incididunt sint nisi. Veniam labore consectetur excepteur ut excepteur laboris commodo esse pariatur reprehenderit exercitation excepteur.", "Ea nulla laborum mollit voluptate eiusmod mollit. Nulla velit exercitation sint qui Lorem nostrud magna aliqua minim irure Lorem anim laborum. Minim fugiat laboris velit aliquip mollit tempor. Minim pariatur et elit pariatur laboris do id. Commodo est do aute esse esse laboris laborum aliquip aliquip minim.", "Exercitation tempor esse esse nisi veniam. Id aliquip tempor est duis magna. Ad dolor veniam irure elit exercitation quis. Aliquip ea sunt exercitation dolor ullamco enim eiusmod duis. Laboris minim dolore velit labore qui. Consectetur elit elit culpa culpa amet labore mollit ex nisi consequat sit eu sunt.", "Lorem reprehenderit ex velit id velit ut. Veniam sint id voluptate tempor ea mollit. Ad adipisicing ipsum esse esse culpa magna voluptate duis aliquip excepteur deserunt esse dolor. Fugiat non pariatur incididunt eu exercitation irure consectetur cillum reprehenderit. Qui eu est nulla ea. Ullamco enim esse labore proident eu amet magna ut reprehenderit labore nostrud. Dolor magna fugiat deserunt adipisicing laborum ad fugiat laborum reprehenderit.", "Officia esse irure nostrud qui adipisicing do voluptate. Sint irure minim laborum laborum tempor veniam. Cupidatat dolor nulla duis qui et minim laborum mollit cupidatat id ut dolore esse. Ullamco do dolor aliquip cillum fugiat elit nisi excepteur veniam quis nisi sint. Velit laboris do mollit pariatur proident occaecat nulla veniam. Exercitation et ut culpa adipisicing aute quis.", "Amet ad anim aliquip id ullamco voluptate fugiat consectetur irure officia consequat. Officia mollit reprehenderit adipisicing elit. Sunt aliqua do esse ex consectetur.", "Anim in in exercitation do est. Aliquip nulla Lorem elit quis sunt reprehenderit consequat officia Lorem consequat. Officia est officia est consectetur fugiat occaecat nostrud labore incididunt eiusmod duis proident labore sunt. Incididunt aliqua consectetur esse labore.", "Consectetur nisi ipsum labore ad aliquip eiusmod dolore dolore sunt officia proident et proident fugiat. Exercitation amet voluptate tempor aliqua et fugiat dolor nostrud et amet. Irure cupidatat officia dolore elit ad incididunt laboris. Adipisicing cillum eu amet magna. Commodo sunt eu incididunt in.", "Lorem adipisicing Lorem et consequat cupidatat. Labore occaecat tempor sint non nisi aute incididunt. Do nulla sunt ex minim proident.", "Aliquip excepteur ullamco aute velit. Nostrud laborum fugiat dolore aliquip labore deserunt cupidatat culpa ipsum. Consequat non consequat sint quis. Nostrud aliquip enim est amet elit minim pariatur velit do eu ut sit exercitation. Amet amet labore exercitation adipisicing minim. Pariatur occaecat nostrud ea qui ea. Id do in eiusmod id.", "Deserunt magna dolore nulla esse dolore aute sunt nisi cupidatat sit aliquip est. Eu ipsum velit mollit sunt ullamco eiusmod amet irure nostrud. Fugiat tempor enim commodo elit sunt ex amet minim veniam tempor labore commodo sint sunt. Ut elit tempor ipsum laboris.", "Elit do reprehenderit minim irure. Sunt irure laborum ea consequat irure ea anim ut mollit do aliquip anim laboris. Cillum labore esse in est mollit dolor magna reprehenderit elit amet ullamco. Dolor irure mollit ut tempor aute aliquip elit veniam. Ad commodo cillum laborum est excepteur magna aliqua do magna.", "Mollit cupidatat minim cillum eiusmod proident magna enim excepteur. Irure duis anim ad reprehenderit anim ut enim anim duis fugiat. Eu consectetur culpa et voluptate veniam. Pariatur est proident dolore incididunt aute laboris ad enim quis exercitation.", "Labore duis tempor in voluptate fugiat elit. Irure culpa culpa consequat nulla incididunt irure aliquip ut. Amet enim minim id id id officia cillum anim sunt ipsum. Laborum quis ex commodo commodo dolore officia reprehenderit ex velit. Ex aliqua eu velit est deserunt nostrud sunt eiusmod exercitation reprehenderit. Qui culpa incididunt aliqua eu. Ullamco sunt incididunt commodo pariatur proident voluptate excepteur aliquip eu nisi laborum.", "Reprehenderit deserunt aliquip nisi tempor consequat eu ipsum fugiat pariatur. Officia consectetur est veniam magna et pariatur nostrud cillum et amet. Id reprehenderit cupidatat dolore qui aute. Laboris laboris duis fugiat dolor laborum velit fugiat voluptate.", "Ad id culpa irure deserunt tempor Lorem nulla commodo eu enim anim excepteur do aliqua. Labore magna incididunt occaecat mollit aliqua officia tempor eu anim Lorem veniam eiusmod velit id. Irure proident nostrud mollit culpa sit.", "Deserunt ullamco anim esse est. Quis consectetur sit eiusmod eiusmod laboris pariatur pariatur nostrud ex velit velit velit id. Cupidatat aute adipisicing dolor et duis sit tempor sit tempor laboris exercitation.", "Excepteur ea laborum sint id pariatur irure commodo in quis non. Sunt eiusmod do sunt anim quis. Excepteur adipisicing non ipsum Lorem cupidatat culpa ullamco esse anim aliqua et culpa fugiat dolore. Ullamco commodo ullamco esse do in enim voluptate. Esse velit qui eu in qui nostrud ea anim eiusmod commodo anim deserunt minim. Quis cillum sint sit ipsum do ullamco aliqua elit dolor occaecat laboris sit excepteur commodo. Aliqua deserunt dolor occaecat nulla aute incididunt commodo cillum dolor excepteur velit.", "Incididunt cillum duis magna eiusmod adipisicing non. Ex magna sit est ad Lorem anim magna. Laboris veniam id cupidatat proident qui culpa ullamco excepteur. Et irure esse labore exercitation enim.", "Fugiat irure dolor commodo ut magna duis aute est culpa dolor cillum veniam. Eiusmod eu ut ut reprehenderit id dolore id exercitation cillum ipsum. Dolor qui magna aliquip enim est fugiat non consectetur voluptate proident magna et duis. Aliqua voluptate veniam ex officia proident qui officia aute aliquip incididunt.", "Nostrud non ex quis irure. Occaecat commodo consequat reprehenderit ipsum. Esse pariatur commodo sunt consequat esse sint excepteur cillum sunt amet labore. Excepteur esse consequat occaecat aute commodo officia dolor aliquip.", "Excepteur magna nostrud qui ad irure et elit duis. Esse officia dolore ad occaecat incididunt deserunt anim. Officia officia amet magna quis duis pariatur minim et qui esse culpa. Deserunt id consectetur irure id pariatur esse. Nulla et nisi sint reprehenderit et.", "Ipsum nisi est exercitation qui nostrud aliqua sit consequat labore. Dolor qui elit nostrud consectetur labore incididunt laboris excepteur est minim do ut adipisicing est. Irure id et aliquip tempor cillum incididunt quis amet velit officia ea. Ut ex duis est labore adipisicing.", "Mollit cillum ipsum esse mollit Lorem ullamco magna cillum. Nisi cillum incididunt qui duis pariatur consectetur proident. Dolor occaecat dolor ea do excepteur mollit dolore ex excepteur nisi dolore eiusmod. Consectetur et consectetur ut duis nulla proident aliquip veniam sit sit sint officia.", "Ex do qui eiusmod id. Duis sunt sunt in veniam. Culpa quis amet aliqua aute sunt amet. Id mollit elit consectetur fugiat exercitation. Velit proident eiusmod veniam ut commodo enim do culpa velit reprehenderit laborum nostrud cupidatat.", "Amet do ipsum cillum eiusmod ex dolor laboris culpa tempor id excepteur nisi aliquip consectetur. Lorem id culpa nostrud voluptate nisi exercitation. Esse id minim velit est fugiat voluptate nisi tempor adipisicing tempor sit veniam.", "Mollit amet adipisicing sunt proident. Labore dolor dolor nulla ex commodo Lorem eu. Magna exercitation laboris officia consectetur pariatur ipsum ullamco officia sunt mollit minim.", "Do in laborum veniam minim. Minim aliquip ipsum excepteur veniam reprehenderit dolore duis reprehenderit sunt veniam occaecat nostrud consectetur. Dolore labore exercitation mollit proident proident ut ipsum nostrud do mollit veniam mollit culpa sunt. Laborum deserunt enim pariatur ea dolor labore pariatur. Reprehenderit laborum ut minim pariatur.", "Id minim magna ex tempor. Laboris dolore dolor laboris reprehenderit exercitation. Laboris id tempor deserunt dolor minim tempor veniam cillum sit. Cillum adipisicing excepteur quis dolore.", "Magna aute et proident do duis quis consectetur nulla aute. Laboris velit ut est fugiat ullamco. Nostrud nulla quis amet est amet adipisicing qui nostrud. Fugiat in qui nostrud occaecat quis excepteur elit laboris dolor Lorem nostrud. Proident irure laborum proident qui consequat.", "Eu officia consectetur consequat consequat in ullamco est nulla. Est duis quis id minim ipsum sit ea culpa ullamco laboris. Cillum voluptate mollit fugiat culpa esse laborum nostrud ipsum commodo. Magna fugiat adipisicing sunt elit nulla dolore dolore pariatur exercitation ut proident ad nostrud aute. Reprehenderit duis amet esse tempor pariatur dolor esse irure fugiat ipsum. Fugiat do proident cillum velit aute culpa qui laborum nostrud aute dolor aliquip labore labore. Qui aute sit ut do qui occaecat esse aliqua aliquip velit fugiat.", "Aliqua adipisicing excepteur minim minim dolore dolor Lorem magna veniam nulla sunt exercitation. Eiusmod eiusmod non ut ad quis id qui aute eu labore non in. Deserunt do quis nostrud consequat amet ipsum dolor excepteur consectetur excepteur minim tempor cupidatat enim. Magna reprehenderit consectetur ipsum in consectetur culpa excepteur deserunt veniam ullamco veniam.", "Occaecat magna laborum cupidatat sint eu laborum id commodo. Officia eu non irure in nisi labore aliqua excepteur sit tempor deserunt nostrud laboris nostrud. Sint consectetur dolore dolor non deserunt adipisicing occaecat in sint.", "Magna laboris irure nisi sit. Voluptate laboris amet amet ullamco nostrud. Ipsum cupidatat cupidatat consectetur officia ut exercitation excepteur officia ut consequat ea ipsum in anim.", "Culpa duis elit sunt enim do ut et. Velit eu esse voluptate irure dolore sit aliquip aliqua et commodo officia duis irure ullamco. Culpa exercitation reprehenderit magna sit nisi aliquip proident eiusmod officia nostrud elit. Excepteur voluptate officia excepteur mollit ut. Id aliqua officia ullamco id enim officia sint ad duis eiusmod magna. Qui cillum sunt quis non.", "Labore voluptate esse cillum eu incididunt mollit enim commodo adipisicing aliquip. Est labore consectetur culpa duis duis veniam consectetur veniam aliqua culpa commodo fugiat nostrud. Deserunt enim aute velit Lorem voluptate. Non in aute ad minim est deserunt. Laboris amet aliqua esse amet cupidatat ut occaecat pariatur. Eu ad velit nisi excepteur.", "Nulla laborum eiusmod laboris non esse laboris pariatur voluptate non consectetur. Ullamco aute exercitation aute ut ex. Non sit ex irure ipsum excepteur aliqua exercitation. Reprehenderit Lorem tempor id cillum nostrud aliquip nostrud commodo sunt et qui culpa.", "Non magna mollit culpa ullamco magna incididunt officia laboris labore proident quis tempor. Proident consectetur sit sunt esse aliquip irure voluptate velit est pariatur qui. Incididunt ullamco velit esse veniam sunt. Nostrud laborum consectetur sunt ad in amet ullamco mollit officia velit minim ut labore. Lorem incididunt cupidatat ipsum incididunt excepteur cillum laboris culpa proident amet adipisicing ipsum commodo.", "Enim id et duis dolore est. In sunt quis id sit mollit ad labore aliqua excepteur sit consectetur pariatur et. Cupidatat aliqua magna irure culpa ex ut cupidatat tempor tempor aliquip nostrud elit nulla. Ad fugiat non adipisicing aliquip aliquip.", "Commodo aute consequat ullamco nostrud ipsum irure quis. Voluptate exercitation ex aute ad reprehenderit proident aliqua. Adipisicing magna qui non eiusmod ullamco est irure qui ea in sint occaecat. Nisi duis voluptate aliqua magna proident cupidatat sint cupidatat eu et consequat non do. Reprehenderit irure laborum eiusmod consectetur dolore occaecat est elit sunt. Velit quis sint labore veniam.", "Magna aute ut mollit consectetur anim fugiat ut occaecat labore voluptate. Occaecat non nostrud amet aliqua ad cupidatat voluptate id velit. Aute id minim laborum quis eu commodo consectetur cillum. Culpa ex aliquip ipsum reprehenderit ea non. Incididunt occaecat excepteur reprehenderit tempor. Sit enim mollit incididunt aliquip duis elit nulla deserunt pariatur magna eiusmod voluptate ex.", "Consectetur fugiat ut in fugiat in laborum mollit amet pariatur esse. Laboris excepteur nisi nostrud ullamco aute laborum nulla esse. Lorem sunt magna fugiat duis sit incididunt officia incididunt mollit. Incididunt consequat nostrud esse fugiat deserunt dolor est laborum. Aliqua Lorem minim aute dolore enim amet fugiat. Nostrud Lorem veniam veniam irure commodo non duis. Fugiat proident minim sit sint commodo adipisicing mollit magna adipisicing ullamco non fugiat.", "Qui culpa aute laborum elit anim sunt aliqua est aliquip officia et amet. Ex sit consequat ullamco nulla. Ut eiusmod ad nulla commodo eu eiusmod officia enim labore magna elit. Laboris nisi in Lorem commodo elit occaecat sint enim id excepteur. Eiusmod proident duis in sunt quis dolor voluptate exercitation. Reprehenderit Lorem ut veniam do aliquip qui id ad cillum adipisicing esse qui culpa. Aute ad exercitation consectetur labore.", "Ad proident aliqua proident consectetur dolor esse sint ullamco officia sint nostrud adipisicing enim. Elit incididunt consequat occaecat Lorem. Eu labore dolor sunt occaecat velit laboris ad consequat aliquip reprehenderit in. Reprehenderit qui qui incididunt sint dolore eiusmod proident ipsum ullamco duis consequat et. Velit laborum consectetur amet anim elit quis enim dolore labore consequat ad duis sint enim. Dolor officia reprehenderit officia laboris id aute anim elit est ut. Officia ullamco voluptate non laborum commodo aliquip sint ad commodo ullamco fugiat.", "Sit mollit adipisicing ullamco cillum ea irure esse sunt ullamco ea magna. Irure labore sit irure proident non laboris culpa do quis ad veniam quis dolor. Pariatur occaecat sint cupidatat veniam laborum minim excepteur. Id magna duis dolor dolore cupidatat minim anim id veniam. Non qui ut in deserunt non duis cupidatat consequat magna incididunt.", "Minim exercitation proident anim fugiat irure nostrud cillum exercitation ut amet dolore anim. Est eu elit culpa amet nulla pariatur reprehenderit deserunt laborum culpa. Magna reprehenderit cupidatat ut Lorem Lorem veniam qui sunt fugiat non occaecat. Occaecat tempor ad mollit cillum exercitation ut in magna nisi veniam anim et velit ut. Eu tempor labore esse ipsum.", "Consequat deserunt ut laboris aliqua esse ad non amet tempor irure. Elit aliqua mollit ut enim et ipsum reprehenderit do tempor magna sint. Dolor ad officia Lorem fugiat in aliqua aliquip aliqua sit. Aliqua dolore fugiat magna laborum nisi magna mollit quis eiusmod ut id dolore laboris amet.", "Mollit exercitation fugiat laboris incididunt. Commodo laboris reprehenderit aute qui tempor est ex aute eu laborum pariatur sint ut. Incididunt labore in incididunt dolor deserunt. Nostrud est est incididunt ex ex aute irure adipisicing. Ullamco ullamco sunt officia ea Lorem occaecat cupidatat.", "Reprehenderit proident consectetur laborum reprehenderit nulla ut veniam. Et eiusmod excepteur est ut culpa sunt aliqua labore nisi. Quis id ad incididunt sunt consequat id eiusmod id nulla.", "Eiusmod fugiat esse proident laborum eiusmod. Do est mollit sint Lorem enim culpa. Proident fugiat mollit commodo culpa Lorem laboris et aute ullamco ex ut officia eiusmod.", "Non fugiat quis deserunt esse aute minim ipsum proident velit dolore aliquip. Pariatur labore magna incididunt nisi velit adipisicing excepteur do enim. Voluptate nisi labore dolor tempor elit eu labore ea minim eu incididunt irure mollit ut.", "Ad velit reprehenderit consectetur eiusmod minim. Labore excepteur irure est pariatur laborum. In sit quis irure excepteur enim adipisicing ea cillum exercitation laboris. Quis ad non consequat proident laboris commodo cupidatat cupidatat sint excepteur nulla officia occaecat pariatur. Cillum aliqua in ex minim ex quis nostrud commodo commodo esse nostrud. Occaecat culpa qui tempor do magna aliqua id ad.", "Excepteur tempor consequat in reprehenderit laborum cupidatat adipisicing dolor commodo veniam eiusmod. Irure eu elit commodo nulla do adipisicing nulla nulla. Dolore voluptate non laborum occaecat sunt nisi et nostrud amet sit ullamco. Dolor esse duis sit aliquip occaecat ad. Ea consectetur magna sunt quis anim ipsum laboris ad irure velit mollit. Sint tempor ullamco culpa est minim magna pariatur anim. Sit voluptate ad consectetur voluptate dolor sint cillum et ex commodo exercitation anim.", "Enim esse aliquip mollit non magna nulla deserunt ullamco occaecat mollit. Ut non est Lorem mollit pariatur. Elit consectetur labore excepteur do occaecat et sit culpa.", "Et et commodo deserunt exercitation fugiat commodo qui ad veniam minim eu. Veniam magna sunt incididunt magna et dolor elit. Eu adipisicing in duis laborum amet ipsum.", "In exercitation minim velit id occaecat. Non deserunt dolore culpa ad nulla veniam anim id quis dolore. Magna dolor aliquip minim cillum ea irure dolor excepteur sunt esse ad sunt nostrud.", "Eu qui ullamco est ullamco do deserunt occaecat elit commodo velit commodo eiusmod enim ullamco. Consectetur Lorem laboris minim pariatur ipsum eiusmod. Est adipisicing aliquip tempor magna enim ex. Labore magna consectetur pariatur ea dolor sint laborum consequat consequat anim. In laboris aliquip aliqua anim do non tempor est. Commodo non et eu elit labore et elit esse. Voluptate adipisicing esse aute anim dolore proident culpa duis ut.", "Eiusmod sit sit nostrud enim ex sit consequat mollit ad officia quis occaecat adipisicing. Sit dolore ad do adipisicing laborum ipsum deserunt id officia deserunt ea minim ea. Aliquip adipisicing reprehenderit dolore laborum aute do enim anim.", "Voluptate cillum esse quis in tempor enim adipisicing aute amet non et cupidatat. Labore cillum consectetur pariatur culpa. Irure amet proident quis et ex est id duis esse.", "Incididunt duis Lorem Lorem tempor et nisi deserunt aliqua quis nostrud. Anim adipisicing ex eiusmod duis ea laborum sunt magna laboris velit. Non elit Lorem eiusmod nostrud culpa cillum dolore nisi enim eu non. Labore ut adipisicing incididunt exercitation ut occaecat ad tempor culpa. Laboris deserunt ea eu ex eu velit aute ullamco fugiat eu quis adipisicing. Magna dolor excepteur culpa cillum.", "Esse labore est incididunt quis voluptate laborum eu commodo duis. Lorem adipisicing ullamco ex ipsum sunt mollit nisi exercitation. Pariatur id minim ex veniam occaecat. Occaecat adipisicing duis Lorem velit quis anim elit ex velit cupidatat consequat id culpa id. Et tempor ut Lorem ut. Sunt consequat eiusmod adipisicing ad reprehenderit non in laborum veniam occaecat laboris. Nulla sint consectetur duis quis consectetur mollit proident elit reprehenderit.", "Exercitation proident dolor irure id proident mollit aliqua deserunt deserunt esse incididunt irure dolore deserunt. Exercitation irure anim ad proident. Cillum cillum fugiat eiusmod occaecat. Duis deserunt fugiat minim eu et quis qui aliqua occaecat tempor non ea exercitation consequat. Cillum Lorem incididunt ullamco est magna qui irure do minim esse deserunt incididunt est.", "In laborum est deserunt ex proident sint commodo. Proident pariatur sunt aliquip anim Lorem ex. Cillum dolor minim consectetur qui aliqua mollit velit ipsum tempor cillum proident officia. Ex culpa duis magna voluptate velit aliqua.", "Occaecat nulla quis pariatur dolor aute in laboris velit proident ex aute ex quis consectetur. Nostrud cupidatat nostrud incididunt quis proident cillum ex est pariatur nisi elit mollit minim commodo. Lorem magna nisi ex qui ex dolor eu.", "Enim ipsum aliquip pariatur labore dolore voluptate. Esse mollit commodo do nisi enim eiusmod tempor mollit Lorem non labore. Consectetur sit nostrud ex nulla mollit proident officia reprehenderit ipsum incididunt exercitation. Pariatur ullamco velit labore ad ex excepteur commodo qui eiusmod amet fugiat quis excepteur laborum. Incididunt enim exercitation id duis et reprehenderit sit exercitation ullamco consequat aliquip.", "Dolor aliquip ullamco voluptate officia eiusmod amet elit id fugiat. Velit occaecat id officia aliquip deserunt quis. Esse proident in eiusmod ex enim veniam nisi ut aliqua id sunt cupidatat.", "Ex laborum reprehenderit voluptate voluptate eu laboris elit consequat elit. In ut ipsum reprehenderit irure sit anim ea sunt ut sit sunt occaecat. Fugiat laboris nulla adipisicing pariatur ea.", "Magna deserunt officia commodo id laboris incididunt Lorem in esse laborum dolore. Velit est enim mollit in amet occaecat consectetur voluptate tempor. Minim irure exercitation anim ut voluptate culpa sint. Proident sit irure in excepteur nostrud aliquip fugiat culpa amet mollit cupidatat nisi tempor proident.", "Elit laboris aute exercitation ea dolor. Sunt id aliqua laboris enim elit duis irure cillum. Culpa consequat Lorem ea esse magna cillum sint irure dolor tempor.", "Commodo amet nisi mollit laborum aute aliquip cupidatat aute consectetur. Ea consectetur in ex Lorem. Quis non laborum laboris laborum deserunt labore adipisicing eiusmod ipsum anim elit voluptate. Et dolore commodo nulla ullamco veniam commodo exercitation aute veniam anim incididunt ad pariatur. Tempor nostrud est consectetur excepteur. Velit elit ullamco aliquip est aliquip ex qui exercitation labore nostrud.", "Adipisicing fugiat cillum elit anim veniam ut consequat mollit qui mollit in nulla cupidatat commodo. Sit dolor non quis proident aliqua reprehenderit consectetur aute mollit proident reprehenderit. Consectetur mollit sit deserunt fugiat ad aliqua et consectetur dolor est culpa labore. Dolore id dolore laboris quis pariatur dolore in proident nisi irure cupidatat. Voluptate ullamco non enim laboris deserunt ea magna voluptate in eiusmod incididunt veniam. Lorem dolore qui consectetur velit sunt elit adipisicing sint. Ea in cillum incididunt excepteur quis mollit minim minim laborum commodo et minim eu Lorem.", "Cupidatat in mollit laborum incididunt. Cillum dolor aliquip aliquip occaecat elit nisi in duis incididunt officia exercitation ea aliqua duis. Anim qui enim culpa quis cillum. Labore fugiat laborum anim ullamco in ex. Non ex dolore velit ex deserunt sint quis ex cupidatat enim. Commodo ut magna amet enim eu sunt nostrud esse cupidatat excepteur. Sit velit ea velit cupidatat ipsum.", "Dolor laborum cillum do do ex irure laborum minim consectetur culpa aliqua mollit. Sunt Lorem aute Lorem cillum amet. Magna eu ea in et fugiat. Quis cillum elit fugiat culpa qui proident nisi nostrud tempor laboris incididunt. Cupidatat ea incididunt voluptate enim cillum elit.", "Voluptate minim non minim id nostrud est dolor ex qui nostrud aute duis ut. Nulla dolor aliqua consequat ullamco ea. Sunt incididunt tempor qui anim tempor irure exercitation elit proident. Mollit sit quis ut mollit labore ipsum sunt adipisicing voluptate incididunt enim laborum ex eiusmod. Est magna labore quis dolor consequat aliqua ad nisi. Minim velit dolore consectetur excepteur culpa commodo. Id laboris irure labore velit et fugiat nulla.", "Amet sit ipsum eiusmod enim excepteur dolor quis amet laboris eu culpa nulla ad. Ad mollit duis est et fugiat aliqua adipisicing est magna exercitation cillum elit. Dolor aliquip non pariatur esse magna aute mollit proident qui officia. Cupidatat officia nostrud aliqua ex sit veniam sint elit. Lorem ut ea id ad officia esse qui. Exercitation dolore consectetur in consectetur proident eu culpa ad quis officia quis mollit reprehenderit dolore.", "Tempor ullamco labore ipsum elit nisi excepteur eiusmod. Esse reprehenderit fugiat commodo esse Lorem quis laboris nisi aliquip amet labore sit. Anim consectetur nostrud in eiusmod. Consequat sit sint aliqua commodo ex nulla velit laboris reprehenderit proident sit magna consectetur. Ea ex dolor excepteur qui velit ad Lorem commodo nulla culpa nulla id commodo sunt. Ea nulla est enim anim.", "Fugiat consequat consectetur consequat laborum. Nisi nisi amet ex non irure duis sint. Esse magna laboris nostrud laborum aliquip. Ut occaecat Lorem velit eiusmod nulla nostrud aliqua. Ad laboris voluptate dolor nisi dolor non. Anim labore exercitation sint pariatur quis. Laborum labore dolore nostrud adipisicing Lorem.", "Ad occaecat deserunt pariatur laborum ipsum minim. Veniam laboris adipisicing proident magna labore dolore excepteur exercitation Lorem sunt voluptate culpa fugiat tempor. Do amet nostrud aliqua enim do dolore proident ex ipsum laboris nisi dolore aliqua.", "Pariatur sint consequat consequat magna. Elit do esse consequat cupidatat enim sit anim. Incididunt aliquip tempor dolore ullamco et minim esse enim officia fugiat.", "Consequat nulla excepteur anim labore sit labore amet ipsum. Non aliquip sit occaecat laborum cupidatat reprehenderit aute veniam ipsum minim nostrud ea. Cupidatat enim quis deserunt id minim duis. Sit exercitation enim quis id mollit aliqua. Pariatur commodo eu veniam magna enim aliquip velit sit ex mollit cupidatat. Esse id ad proident magna. Ut quis est excepteur duis eiusmod quis elit cupidatat dolore officia veniam excepteur irure consectetur.", "Aute officia et esse consectetur ut labore velit laborum consequat. Eiusmod eu enim occaecat eu enim exercitation qui mollit in excepteur officia exercitation ad. Non quis aute dolor quis elit ad. Voluptate proident ea laboris labore amet. Aute culpa tempor exercitation adipisicing labore qui nisi tempor. Non sunt cillum sint deserunt non enim amet aute laboris consequat veniam magna proident cupidatat. Irure duis adipisicing eu ex exercitation eiusmod.", "Labore ex dolore labore ad sunt. Amet ipsum ex voluptate nostrud cupidatat occaecat occaecat. Ut est consectetur qui aliqua incididunt proident ullamco. Ex elit officia elit anim nostrud eiusmod amet. Aute commodo enim nostrud adipisicing. Dolore sint duis elit nostrud in velit mollit nisi elit.", "Laborum aliqua eu labore eiusmod mollit labore officia. Incididunt culpa ex incididunt ex non cupidatat eiusmod aliquip sunt. Eu veniam ex ipsum sint exercitation laborum non aliquip laborum irure culpa. Eiusmod culpa ipsum ad fugiat Lorem labore non. Aliquip dolor occaecat incididunt enim nostrud id ipsum quis irure exercitation et enim enim. Minim ullamco eiusmod quis adipisicing qui do tempor. Anim ut enim culpa non deserunt proident duis cillum veniam aute ut fugiat velit qui.", "Reprehenderit occaecat ut anim ut magna ut elit labore cillum mollit laborum. Amet magna officia do anim do fugiat dolore et dolore est. In qui incididunt anim occaecat commodo est incididunt sunt minim. Minim laborum aliquip et adipisicing commodo culpa cupidatat id nisi duis. Dolor magna reprehenderit ad eu proident nulla pariatur non.", "Velit culpa ea anim reprehenderit. Lorem laboris pariatur ullamco esse ea nostrud dolor deserunt duis veniam duis nisi. Ex quis ex amet quis in quis ipsum laborum consequat exercitation. Aliquip ad consequat dolor reprehenderit occaecat veniam enim anim ipsum elit commodo.", "Nulla quis consectetur minim non elit irure do aute veniam minim. Deserunt do ipsum do consequat. Anim qui quis ad eiusmod tempor qui irure sint commodo labore. Aliqua aute sit in occaecat.", "Officia sit enim aute adipisicing culpa dolor fugiat cupidatat. Id minim dolor est deserunt fugiat irure pariatur adipisicing aute. Adipisicing officia exercitation exercitation aliquip id. Proident laborum velit labore laborum laboris dolore est proident nisi. Amet occaecat officia ea elit velit. Nisi eiusmod incididunt officia cillum est aliqua ex aliquip elit aliquip esse tempor anim.", "Exercitation quis in elit commodo incididunt pariatur non nisi minim officia anim sunt deserunt. Ex irure commodo officia ad commodo incididunt Lorem. Mollit tempor mollit laborum nulla exercitation nulla incididunt consequat incididunt. Id amet enim id magna enim sint id laboris sint commodo fugiat dolore. Pariatur est mollit in incididunt voluptate.", "Incididunt sit consectetur irure amet. Cillum aliquip reprehenderit aliqua id officia velit culpa irure. Sit mollit quis dolore ex dolore voluptate et Lorem ex commodo. Dolor magna enim enim ullamco ea nulla.", "Culpa esse exercitation incididunt proident tempor ex incididunt laborum anim pariatur amet elit nostrud esse. Sit consequat sint aute nostrud sit sint anim voluptate ipsum non velit. Id quis dolore eiusmod nulla adipisicing et consequat ea consequat dolore reprehenderit.", "Ullamco eiusmod nostrud est commodo nostrud. Amet consequat nisi id proident cupidatat exercitation labore amet eu occaecat officia dolor. Sit esse est ullamco et reprehenderit.", "Adipisicing aliquip dolor aute anim eiusmod aute ut ad voluptate mollit ullamco fugiat nulla. Duis do ex laborum consectetur irure laboris incididunt. Id officia nulla nisi occaecat duis dolore consequat deserunt quis id nulla do id. Occaecat nostrud ea ipsum elit ipsum pariatur. Fugiat incididunt Lorem eu cupidatat reprehenderit cillum dolore reprehenderit laboris ullamco minim. Occaecat voluptate qui non anim minim non ut fugiat velit proident cupidatat cillum.", "Esse nisi veniam deserunt consequat elit sunt anim occaecat. Pariatur consequat irure elit labore laboris labore aute est velit. Cillum aute quis ullamco enim fugiat id sit et occaecat et. Fugiat ut et sit sint cillum in tempor in reprehenderit consequat nostrud anim pariatur. Anim sit aute qui nisi dolore eiusmod enim sint. Incididunt dolor adipisicing velit irure Lorem sunt adipisicing pariatur dolore mollit aliqua pariatur.", "Aute excepteur et cupidatat commodo fugiat non cupidatat consectetur enim pariatur ex. Deserunt deserunt velit minim do ipsum eu sunt magna ad. Veniam dolore elit sint aliqua ex. Et commodo ipsum in exercitation occaecat aliquip enim velit sunt nulla. Reprehenderit do officia quis irure labore pariatur ad voluptate voluptate. Ipsum elit velit minim fugiat laboris non excepteur Lorem amet et Lorem mollit et esse. Minim ullamco aute in quis quis reprehenderit sunt deserunt aliquip excepteur ullamco aliqua sint.", "Non in mollit aute aliqua. Sint laborum adipisicing sit duis elit amet deserunt id magna qui dolor et incididunt. Veniam magna ullamco dolore anim elit ad.", "Nisi officia ad aute ex. Ea deserunt nisi fugiat dolore pariatur fugiat reprehenderit nostrud exercitation. Adipisicing id enim duis laboris nulla ullamco sit dolor incididunt excepteur. Do aute et ex enim mollit magna eu enim. Officia ad ipsum mollit ullamco aliquip proident sint aliqua Lorem nulla. Eu officia qui mollit proident magna cupidatat ad enim.", "Labore ad adipisicing esse ex eu. Minim ut ea laboris elit cupidatat eiusmod. Commodo Lorem esse laborum do dolore cillum cupidatat incididunt culpa nulla qui ea voluptate ad. Veniam ipsum fugiat laborum reprehenderit. Minim ea cillum irure quis amet enim esse ullamco quis ipsum dolor. Laboris non labore laboris qui incididunt ipsum.", "Officia labore minim ullamco qui commodo qui. Lorem consequat amet minim do sit magna duis. Velit commodo nisi in adipisicing nisi voluptate ex enim sunt voluptate ullamco est dolor. Nisi voluptate eiusmod tempor qui occaecat enim est ullamco deserunt. Excepteur exercitation deserunt quis est cupidatat nulla do nostrud. Voluptate magna consectetur adipisicing non eu Lorem aliqua ex anim consequat id fugiat.", "Aliquip anim mollit ut duis labore. Et dolor ipsum dolore anim excepteur ullamco adipisicing laborum quis veniam consectetur nisi incididunt duis. Sit laborum tempor ullamco mollit. Aliqua amet cillum consequat minim duis aute culpa ad dolor proident adipisicing nisi exercitation. Proident voluptate dolore eu velit enim elit magna eu sint consequat ipsum in ad. Dolore ullamco exercitation tempor non consectetur quis pariatur elit est exercitation sit.", "Adipisicing veniam reprehenderit nisi sunt ad ullamco amet labore aliquip in. Quis in id tempor sunt cupidatat ea eiusmod pariatur ut officia id. Proident ea quis eiusmod in qui tempor. Eu quis dolore pariatur ut dolore laborum do enim nostrud irure voluptate proident ullamco dolor." };
    int index = 0;

    foreach (VNTRSSItem* rssItem, rssChannel->getRSSItems()) {
        QCOMPARE(rssItem->getDescription(), descriptions[index]);
        QCOMPARE(rssItem->getPlainDescription(), plainDescriptions[index++]);
    }
}

void UnitTests::testRSSSiteBarDate() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-bar.xml");
    QCOMPARE(rssChannel->getDate(), this->getSimpleDateFormatRSS("Thu, 13 Nov 2014 20:05:00 +0100"));
}

void UnitTests::testRSSSiteBarLink() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-bar.xml");
    QCOMPARE(rssChannel->getLink(), QUrl("http://www.example.bar/Bar"));
}

void UnitTests::testRSSSiteBarImageInternet() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-bar.xml");
    QCOMPARE(rssChannel->getImageUrl(), QUrl("http://example.bar/logo_rss.png"));
    QCOMPARE(rssChannel->getImageFileType(), QString("png"));
}

void UnitTests::testRSSSiteBarLanguage() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-bar.xml");
    QCOMPARE(rssChannel->getLanguage(), QString("en"));
}

void UnitTests::testRSSSiteBarTitle() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-bar.xml");
    QCOMPARE(rssChannel->getTitle(), QString("Bar"));
    QCOMPARE(rssChannel->getPlainTitle(), QString("Bar"));
}

void UnitTests::testRSSSiteBarDescription() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-bar.xml");
    QCOMPARE(rssChannel->getDescription(), QString("Test bar bar bar bar"));
    QCOMPARE(rssChannel->getPlainDescription(), QString("Test bar bar bar bar"));
}

void UnitTests::testRSSSiteBarItemSize() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-bar.xml");
    QList<VNTRSSItem*> rssItems = rssChannel->getRSSItems();
    QCOMPARE(rssItems.size(), 15);
}

void UnitTests::testRSSSiteBarItemLink() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-bar.xml");
    QString links[] = { "http://example.bar/02366d1b", "http://example.bar/5f8e5630", "http://example.bar/2624b369", "http://example.bar/6cb8692e", "http://example.bar/e3124644", "http://example.bar/0ca3a682", "http://example.bar/07d865bb", "http://example.bar/028d7a8e", "http://example.bar/5ff7b5ca", "http://example.bar/71e191c7", "http://example.bar/53a11c43", "http://example.bar/ed4a9775", "http://example.bar/edf9b10c", "http://example.bar/caf65628", "http://example.bar/dfc8c68b" };
    int index = 0;

    foreach (VNTRSSItem* rssItem, rssChannel->getRSSItems()) {
        QCOMPARE(rssItem->getLink(), QUrl(links[index++]));
    }
}

void UnitTests::testRSSSiteBarItemDate() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-bar.xml");
    QString dates[] = { "Thu, 13 Nov 2014 20:05:00 +0100", "Thu, 13 Nov 2014 19:41:00 +0100", "Thu, 13 Nov 2014 16:38:00 +0100", "Thu, 13 Nov 2014 15:45:00 +0100", "Thu, 13 Nov 2014 15:39:00 +0100", "Thu, 13 Nov 2014 15:00:00 +0100", "Thu, 13 Nov 2014 13:40:00 +0100", "Thu, 13 Nov 2014 11:33:00 +0100", "Thu, 13 Nov 2014 05:49:00 +0100", "Wed, 12 Nov 2014 19:32:00 +0100", "Wed, 12 Nov 2014 19:20:00 +0100", "Wed, 12 Nov 2014 17:03:00 +0100", "Wed, 12 Nov 2014 16:17:00 +0100", "Wed, 12 Nov 2014 14:56:00 +0100", "Wed, 12 Nov 2014 14:30:00 +0100" };
    int index = 0;

    foreach (VNTRSSItem* rssItem, rssChannel->getRSSItems()) {
        QCOMPARE(rssItem->getDate(), this->getSimpleDateFormatRSS(dates[index++]));
    }
}

void UnitTests::testRSSSiteBarItemTitle() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-bar.xml");
    QString titles[] = { "voluptate aliqua aliqua id ad non dolor et cupidatat incididunt", "proident anim nisi commodo ad velit cupidatat do nulla fugiat", "qui sint officia minim nulla ea veniam excepteur cillum laborum", "ipsum amet culpa commodo ullamco qui culpa ullamco ut pariatur", "ut eiusmod nulla quis cupidatat irure ea tempor minim magna", "quis nisi aliqua occaecat est nulla occaecat tempor sint aute", "ullamco occaecat nisi nisi aute cillum duis elit irure quis", "id commodo ipsum reprehenderit exercitation cillum ullamco ullamco nostrud est", "culpa do dolore quis magna incididunt velit commodo ea voluptate", "culpa proident labore id anim mollit exercitation commodo eiusmod ex", "pariatur tempor cupidatat deserunt nulla ipsum aliquip ad nisi sunt", "id adipisicing sunt ullamco Lorem do qui sint cupidatat veniam", "tempor pariatur pariatur adipisicing laboris cupidatat laborum occaecat sint mollit", "et esse consequat non ut ea labore nulla magna minim", "ea ex reprehenderit nostrud proident incididunt ullamco aliqua consectetur cupidatat" };
    QString plainTitles[] = { "voluptate aliqua aliqua id ad non dolor et cupidatat incididunt", "proident anim nisi commodo ad velit cupidatat do nulla fugiat", "qui sint officia minim nulla ea veniam excepteur cillum laborum", "ipsum amet culpa commodo ullamco qui culpa ullamco ut pariatur", "ut eiusmod nulla quis cupidatat irure ea tempor minim magna", "quis nisi aliqua occaecat est nulla occaecat tempor sint aute", "ullamco occaecat nisi nisi aute cillum duis elit irure quis", "id commodo ipsum reprehenderit exercitation cillum ullamco ullamco nostrud est", "culpa do dolore quis magna incididunt velit commodo ea voluptate", "culpa proident labore id anim mollit exercitation commodo eiusmod ex", "pariatur tempor cupidatat deserunt nulla ipsum aliquip ad nisi sunt", "id adipisicing sunt ullamco Lorem do qui sint cupidatat veniam", "tempor pariatur pariatur adipisicing laboris cupidatat laborum occaecat sint mollit", "et esse consequat non ut ea labore nulla magna minim", "ea ex reprehenderit nostrud proident incididunt ullamco aliqua consectetur cupidatat" };
    int index = 0;

    foreach (VNTRSSItem* rssItem, rssChannel->getRSSItems()) {
        QCOMPARE(rssItem->getTitle(), titles[index]);
        QCOMPARE(rssItem->getPlainTitle(), plainTitles[index++]);
    }
}

void UnitTests::testRSSSiteBarItemImageInternet() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-bar.xml");
    QString images[] = { NULL, NULL, "http://example.bar/polopoly_fs/1.2108565.1409301305/135x135/image.jpg", "http://example.bar/polopoly_fs/1.2219688.1415889150/135x135/image.jpg", "http://example.bar/polopoly_fs/1.2219636.1415888072/135x135/image.jpg", "http://example.bar/image/1.1873086.1415812625/135x135/image.jpg", NULL, NULL, NULL, "http://example.bar/polopoly_fs/1.2218567.1415812265/135x135/image.jpg", "http://example.bar/polopoly_fs/1.2218602.1415814755/135x135/image.jpg", "http://example.bar/polopoly_fs/1.2218402.1415808212/135x135/image.jpg", "http://example.bar/polopoly_fs/1.2215030.1415698482/135x135/image.jpg", "http://example.bar/image/1.2217766.1415803052/135x135/image.jpg", "http://example.bar/polopoly_fs/1.2216721.1415781514/135x135/image.jpg" };
    int index = 0;

    foreach (VNTRSSItem* rssItem, rssChannel->getRSSItems()) {
        QCOMPARE(rssItem->getImageUrl(), QUrl(images[index++]));
    }
}

void UnitTests::testRSSSiteBarItemPlainDescription() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-bar.xml");
    QString plainDescriptions[] = { "Et aute id Lorem enim deserunt ipsum deserunt. Irure eu eiusmod quis magna esse Lorem. Veniam ullamco veniam officia et cillum laborum qui.", "Nostrud laboris fugiat eiusmod ad in enim esse. Excepteur commodo esse labore consectetur laboris tempor anim ut enim culpa exercitation officia sunt non. Exercitation consectetur culpa officia eiusmod ullamco dolore est. Sunt sint nostrud cupidatat enim esse dolor eu pariatur officia ullamco voluptate excepteur irure. Cupidatat labore nisi velit minim esse mollit id proident irure ad irure pariatur.", "Proident ad reprehenderit ea consequat ipsum ea duis ex pariatur. Est officia laboris incididunt sit et consequat ex consectetur nulla velit exercitation adipisicing amet. Est fugiat mollit ipsum nisi dolor ipsum aliqua aute nulla id magna ipsum aliquip.", "Officia magna amet nulla magna nostrud exercitation nostrud officia. Laborum pariatur dolor consequat laborum in fugiat ipsum adipisicing deserunt. Ullamco duis irure dolore laborum culpa. Ad dolor culpa proident quis anim dolore incididunt reprehenderit esse eiusmod ea proident non sit. Aliquip aute aliquip ipsum quis nulla in irure deserunt.", "Non occaecat proident cillum enim. Cillum cupidatat sunt sint ad eu irure excepteur ut. Sint non id ex aute veniam eu nulla eiusmod. Exercitation commodo culpa cupidatat aliquip culpa do in consectetur nulla ea aliquip in. Laborum velit esse fugiat do enim non ipsum elit velit occaecat in anim do sunt. Et aliquip commodo consequat duis enim dolore fugiat adipisicing qui ex laboris sint ullamco amet.", "Deserunt est ad nisi culpa reprehenderit ullamco laborum nulla dolore non cillum sint. Laboris sint irure eiusmod sint laborum quis sint quis eu consectetur sit ad quis. Deserunt est culpa do irure officia. Consectetur esse commodo magna nostrud mollit. Qui elit occaecat ullamco elit aliquip cupidatat nulla nulla ut eu aliquip. Laboris amet duis labore ad et nulla.", "Esse mollit mollit nulla quis nostrud ea pariatur. Nulla aute consectetur nostrud culpa exercitation. Ad labore et tempor reprehenderit. Consequat excepteur officia aute reprehenderit cillum nostrud. Consequat consectetur est sint nisi ad eiusmod consectetur ut veniam Lorem laboris. Labore aliquip sit velit dolor in amet eiusmod veniam. Nostrud do velit cupidatat eiusmod Lorem deserunt sit.", "Cillum cillum velit nulla dolore ex commodo quis aliquip pariatur enim amet. Proident ipsum magna sint sint tempor ad. Proident laborum sit nulla eu amet culpa pariatur sunt adipisicing est proident. Ut sint amet nostrud sint amet veniam nostrud laboris fugiat fugiat anim esse veniam. Et ullamco officia dolore fugiat.", "Elit quis quis est quis consectetur excepteur pariatur consectetur proident. Irure aute laborum pariatur in dolor incididunt proident eu do consequat. Nulla cillum sunt excepteur enim occaecat consectetur. Minim est dolore excepteur ea velit anim aliquip adipisicing laborum dolore deserunt. Occaecat mollit eu ex id ea proident non ad veniam tempor eu irure pariatur ullamco. Do fugiat quis officia ex deserunt ut sunt culpa. Tempor mollit nisi consequat consectetur velit anim mollit minim adipisicing labore.", "Qui ex aliquip voluptate exercitation nostrud cillum sunt tempor ipsum commodo. Nostrud ipsum quis culpa quis consectetur incididunt culpa dolor duis. Duis laborum ipsum adipisicing ullamco anim proident fugiat do amet.", "Nisi deserunt fugiat qui irure sit laborum. Velit pariatur velit duis velit occaecat do. Aliquip veniam enim fugiat enim cillum pariatur officia mollit sint sint in nostrud. Culpa proident ex do do proident aliquip ut.", "Qui et sit nisi incididunt non eu amet. Nostrud tempor eu qui amet id ipsum minim aliqua dolor qui irure irure. Irure ea deserunt reprehenderit laborum ut dolore adipisicing commodo pariatur excepteur excepteur. Laborum consectetur reprehenderit id tempor duis nostrud mollit dolore anim Lorem sint. Veniam voluptate nulla voluptate ad amet. Exercitation sint consectetur aute exercitation. Ad non qui nulla velit aute adipisicing mollit.", "Ipsum amet nostrud ullamco voluptate laboris elit non ullamco nulla cupidatat duis eu. Excepteur aute labore nostrud amet eu nisi proident qui sint velit. Sit do proident non velit magna commodo. Culpa est nostrud amet fugiat deserunt nulla. Eiusmod voluptate adipisicing qui est et.", "Nisi sunt minim mollit fugiat deserunt id et fugiat voluptate qui velit ullamco. Non qui eiusmod anim incididunt ipsum veniam nulla minim ut ullamco aute nulla dolor. Et reprehenderit eiusmod aliqua adipisicing est magna id ut culpa sunt non. Occaecat minim reprehenderit voluptate eu velit anim. Dolore dolore culpa nisi minim aute consequat occaecat.", "Laboris dolore commodo eu pariatur dolore commodo excepteur ipsum. Aliquip ullamco quis fugiat cupidatat eu culpa adipisicing in amet. Do magna est consectetur id laborum. Enim amet incididunt dolore deserunt ex irure qui consectetur id amet minim. Anim sunt non culpa quis voluptate nisi esse sit in anim adipisicing id eiusmod incididunt." };
    int index = 0;

    foreach (VNTRSSItem* rssItem, rssChannel->getRSSItems()) {
        QCOMPARE(rssItem->getPlainDescription(), plainDescriptions[index++]);
    }
}

void UnitTests::testRSSSiteExampleDate() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-example.xml");
    QCOMPARE(rssChannel->getDate(), QDateTime());
}

void UnitTests::testRSSSiteExampleLink() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-example.xml");
    QCOMPARE(rssChannel->getLink(), QUrl("http://www.example.org/"));
}

void UnitTests::testRSSSiteExampleImageInternet() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-example.xml");
    QCOMPARE(rssChannel->getImageUrl(), QUrl());
    QCOMPARE(rssChannel->getImageFileType(), QString());
}

void UnitTests::testRSSSiteExampleLanguage() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-example.xml");
    QCOMPARE(rssChannel->getLanguage(), QString(""));
}

void UnitTests::testRSSSiteExampleTitle() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-example.xml");
    QCOMPARE(rssChannel->getTitle(), QString("Example title"));
    QCOMPARE(rssChannel->getPlainTitle(), QString("Example title"));
}

void UnitTests::testRSSSiteExampleDescription() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-example.xml");
    QCOMPARE(rssChannel->getDescription(), QString("Example description"));
    QCOMPARE(rssChannel->getPlainDescription(), QString("Example description"));
}

void UnitTests::testRSSSiteExampleItemSize() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-example.xml");
    QList<VNTRSSItem*> rssItems = rssChannel->getRSSItems();
    QCOMPARE(rssItems.size(), 20);
}

void UnitTests::testRSSSiteExampleItemLink() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-example.xml");
    QString links[] = { "http://example.org/b3e74a2a-4f0f.html", "http://example.org/27e641c8-2aab.html", "http://example.org/88ad999e-72ec.html", "http://example.org/b8c9403b-9fda.html", "http://example.org/51f09f1a-5b20.html", "http://example.org/bc9826cf-4d51.html", "http://example.org/bc1123bf-3053.html", "http://example.org/2d093f16-b409.html", "http://example.org/4f99cd2a-58cf.html", "http://example.org/f922e8a6-6858.html", "http://example.org/f38437e8-fc5e.html", "http://example.org/55cdf187-75a4.html", "http://example.org/61711c9a-bb60.html", "http://example.org/e6dfd5ca-fe18.html", "http://example.org/fa06e360-df1d.html", "http://example.org/d71b7f85-6476.html", "http://example.org/8d448ef2-86c0.html", "http://example.org/33647027-3906.html", "http://example.org/f8d5ab84-775d.html", "http://example.org/ac3b396d-0d95.html" };
    int index = 0;

    foreach (VNTRSSItem* rssItem, rssChannel->getRSSItems()) {
        QCOMPARE(rssItem->getLink(), QUrl(links[index++]));
    }
}

void UnitTests::testRSSSiteExampleItemDate() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-example.xml");
    QString dates[] = { "Fri, 14 Nov 2014 14:39:24 GMT", "Fri, 14 Nov 2014 14:09:49 GMT", "Fri, 14 Nov 2014 12:32:17 GMT", "Fri, 14 Nov 2014 11:22:10 GMT", "Fri, 14 Nov 2014 09:49:38 GMT", "Fri, 14 Nov 2014 07:36:42 GMT", "Fri, 14 Nov 2014 06:45:27 GMT", "Thu, 13 Nov 2014 23:57:48 GMT", "Thu, 13 Nov 2014 21:27:23 GMT", "Thu, 13 Nov 2014 18:54:27 GMT", "Thu, 13 Nov 2014 15:12:28 GMT", "Thu, 13 Nov 2014 12:44:02 GMT", "Thu, 13 Nov 2014 12:31:03 GMT", "Thu, 13 Nov 2014 12:22:56 GMT", "Thu, 13 Nov 2014 12:19:04 GMT", "Thu, 13 Nov 2014 12:12:42 GMT", "Thu, 13 Nov 2014 09:00:59 GMT", "Thu, 13 Nov 2014 08:54:24 GMT", "Thu, 13 Nov 2014 08:45:48 GMT", "Wed, 12 Nov 2014 20:14:21 GMT" };
    int index = 0;

    foreach (VNTRSSItem* rssItem, rssChannel->getRSSItems()) {
        QCOMPARE(rssItem->getDate(), this->getSimpleDateFormatRSS(dates[index++]));
    }
}

void UnitTests::testRSSSiteExampleItemTitle() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-example.xml");
    QString titles[] = { "reprehenderit aliqua ut deserunt consequat -\nminim duis labore voluptate aliquip", "velit nulla cupidatat ut exercitation -\nmollit dolore in est reprehenderit", "id cupidatat nostrud duis amet -\nlaborum aute minim non adipisicing", "aliqua aute fugiat ad est -\nex amet mollit nostrud labore", "elit sint tempor ad cupidatat -\nexcepteur amet ipsum nostrud magna", "ut nostrud amet eu esse -\nincididunt ex ipsum consectetur proident", "esse officia Lorem ut id -\nlaboris proident ullamco eiusmod amet", "est tempor eu qui elit -\nsunt reprehenderit sunt consequat non", "proident ut elit sunt eiusmod -\nnulla et nostrud et proident", "incididunt commodo aliquip commodo fugiat -\nexercitation ad minim proident magna", "minim quis enim anim velit -\nanim est do labore voluptate", "tempor excepteur culpa velit laborum -\ndeserunt veniam laboris labore magna", "aliquip Lorem laboris laborum enim -\nsunt cupidatat nulla tempor laborum", "adipisicing mollit voluptate aliquip amet -\npariatur magna eiusmod proident incididunt", "velit sint fugiat reprehenderit ipsum -\nut magna enim dolore ea", "cupidatat aute culpa mollit officia -\nad exercitation id voluptate velit", "reprehenderit consectetur in quis officia -\nlabore mollit ex dolor duis", "consectetur incididunt qui consectetur occaecat -\nveniam officia ea laboris culpa", "ipsum tempor nostrud cillum occaecat -\nvoluptate id excepteur enim veniam", "in tempor voluptate nisi deserunt -\nexercitation minim et voluptate dolore" };
    QString plainTitles[] = { "reprehenderit aliqua ut deserunt consequat - minim duis labore voluptate aliquip", "velit nulla cupidatat ut exercitation - mollit dolore in est reprehenderit", "id cupidatat nostrud duis amet - laborum aute minim non adipisicing", "aliqua aute fugiat ad est - ex amet mollit nostrud labore", "elit sint tempor ad cupidatat - excepteur amet ipsum nostrud magna", "ut nostrud amet eu esse - incididunt ex ipsum consectetur proident", "esse officia Lorem ut id - laboris proident ullamco eiusmod amet", "est tempor eu qui elit - sunt reprehenderit sunt consequat non", "proident ut elit sunt eiusmod - nulla et nostrud et proident", "incididunt commodo aliquip commodo fugiat - exercitation ad minim proident magna", "minim quis enim anim velit - anim est do labore voluptate", "tempor excepteur culpa velit laborum - deserunt veniam laboris labore magna", "aliquip Lorem laboris laborum enim - sunt cupidatat nulla tempor laborum", "adipisicing mollit voluptate aliquip amet - pariatur magna eiusmod proident incididunt", "velit sint fugiat reprehenderit ipsum - ut magna enim dolore ea", "cupidatat aute culpa mollit officia - ad exercitation id voluptate velit", "reprehenderit consectetur in quis officia - labore mollit ex dolor duis", "consectetur incididunt qui consectetur occaecat - veniam officia ea laboris culpa", "ipsum tempor nostrud cillum occaecat - voluptate id excepteur enim veniam", "in tempor voluptate nisi deserunt - exercitation minim et voluptate dolore" };
    int index = 0;

    foreach (VNTRSSItem* rssItem, rssChannel->getRSSItems()) {
        QCOMPARE(rssItem->getTitle(), titles[index]);
        QCOMPARE(rssItem->getPlainTitle(), plainTitles[index++]);
    }
}

void UnitTests::testRSSSiteExampleItemImage() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-example.xml");
    QString images[] = { "http://cdn.example.org/image/5711486/thumbnail.jpg", "http://cdn.example.org/image/5711396/thumbnail.jpg", "http://cdn.example.org/image/5709784/thumbnail.jpg", "http://cdn.example.org/image/5708752/thumbnail.jpg", "http://cdn.example.org/image/5709204/thumbnail.jpg", "http://cdn.example.org/image/5708516/thumbnail.jpg", "http://cdn.example.org/image/5708254/thumbnail.jpg", "http://cdn.example.org/image/5707816/thumbnail.jpg", "http://cdn.example.org/image/5707838/thumbnail.jpg", "http://cdn.example.org/image/5706852/thumbnail.jpg", "http://cdn.example.org/image/5705870/thumbnail.jpg", "http://cdn.example.org/image/5702682/thumbnail.jpg", "http://cdn.example.org/image/5704076/thumbnail.jpg", "http://cdn.example.org/image/5703500/thumbnail.jpg", "http://cdn.example.org/image/5704094/thumbnail.jpg", "http://cdn.example.org/image/5703998/thumbnail.jpg", "http://cdn.example.org/image/5702522/thumbnail.jpg", "http://cdn.example.org/image/5702214/thumbnail.jpg", "http://cdn.example.org/image/5702282/thumbnail.jpg", "http://cdn.example.org/image/5701048/thumbnail.jpg" };
    int index = 0;

    foreach (VNTRSSItem* rssItem, rssChannel->getRSSItems()) {
        QCOMPARE(rssItem->getImageUrl(), QUrl(images[index++]));
        QCOMPARE(rssItem->getImageFileType(), QString("jpg"));
    }
}

void UnitTests::testRSSSiteExampleItemDescription() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-example.xml");
    QString descriptions[] = { "Minim qui aliquip adipisicing pariatur aliqua tempor. Amet fugiat labore eiusmod sit fugiat adipisicing reprehenderit ad cupidatat nisi eiusmod ut enim. Do sint nulla aliqua occaecat dolore sit esse laboris ad labore. Cillum labore incididunt aliqua commodo. Adipisicing et Lorem deserunt consequat velit. Est ipsum Lorem enim commodo sit esse eu cillum veniam qui labore.<img src=\"http://example.org/b3e74a2a-4f0f/b3e74a2a-4f0f\" height=\"1\" width=\"1\"/>", "Consequat ut in voluptate qui magna esse veniam. Excepteur velit enim aliqua elit irure et aliquip velit. Mollit proident cupidatat aliquip dolor enim enim anim magna elit. In fugiat sint et id mollit.<img src=\"http://example.org/27e641c8-2aab/27e641c8-2aab\" height=\"1\" width=\"1\"/>", "Ipsum reprehenderit aliquip veniam sint mollit deserunt ex ipsum. Eiusmod incididunt amet mollit eiusmod aliqua consectetur eu tempor qui ex occaecat tempor id cillum. Sit ad excepteur officia minim in. Deserunt dolor velit irure deserunt est consectetur labore pariatur cillum.<img src=\"http://example.org/88ad999e-72ec/88ad999e-72ec\" height=\"1\" width=\"1\"/>", "Id voluptate qui officia occaecat enim proident ad. Esse irure ex mollit ad enim ipsum duis nisi do eu. Tempor duis esse sint occaecat qui sint deserunt consequat dolore tempor eiusmod ullamco aute. Ea non ea eiusmod adipisicing Lorem exercitation.<img src=\"http://example.org/b8c9403b-9fda/b8c9403b-9fda\" height=\"1\" width=\"1\"/>", "Cillum enim anim aliquip sint. Esse nulla irure consectetur proident dolor consectetur qui. Do laboris eu qui in cillum. Cillum velit commodo quis occaecat elit ut cillum eu irure.<img src=\"http://example.org/51f09f1a-5b20/51f09f1a-5b20\" height=\"1\" width=\"1\"/>", "Aute sunt officia labore ullamco laborum. Et voluptate ex dolore ut labore commodo dolor aute aliqua. Fugiat sunt officia aliquip occaecat exercitation sunt velit id ullamco pariatur. Esse aliquip nisi anim aliquip incididunt Lorem consectetur eu magna. Duis non quis minim tempor sit proident enim. Sit reprehenderit pariatur id veniam. Cupidatat ad commodo veniam minim occaecat deserunt.<img src=\"http://example.org/bc9826cf-4d51/bc9826cf-4d51\" height=\"1\" width=\"1\"/>", "Adipisicing in anim velit do aliquip nisi aute. Cupidatat cupidatat ea est ipsum esse consectetur ea tempor incididunt culpa elit. Magna magna consequat nisi velit aliqua do. Non dolor eu incididunt id sit Lorem nulla. Fugiat elit minim irure deserunt officia quis tempor sint sint sunt mollit tempor proident do. Reprehenderit veniam do consequat cupidatat duis elit magna et enim sunt deserunt sunt. Qui laboris Lorem sit magna in commodo cillum.<img src=\"http://example.org/bc1123bf-3053/bc1123bf-3053\" height=\"1\" width=\"1\"/>", "Officia esse ex tempor irure do ea in cupidatat minim nisi laborum dolor cillum. Mollit sit minim sunt irure reprehenderit esse. Exercitation occaecat sint magna ea sunt reprehenderit reprehenderit. Id eu ipsum incididunt consequat ut magna ea occaecat mollit qui aliqua. Minim elit quis ea nisi aliquip exercitation enim cillum non excepteur dolor duis.<img src=\"http://example.org/2d093f16-b409/2d093f16-b409\" height=\"1\" width=\"1\"/>", "Mollit occaecat sunt qui cillum cupidatat magna adipisicing anim tempor quis sunt laboris mollit. Enim adipisicing qui culpa ullamco aliqua ad quis. Sunt laborum excepteur ad laboris dolor adipisicing labore labore occaecat. Qui consequat ea ut fugiat tempor excepteur cillum laboris minim laboris voluptate. Cupidatat reprehenderit cillum aliquip incididunt eiusmod. Cupidatat aute commodo ipsum sit aliquip quis excepteur in esse laboris velit cillum culpa fugiat. Do duis duis sit mollit duis non est.<img src=\"http://example.org/4f99cd2a-58cf/4f99cd2a-58cf\" height=\"1\" width=\"1\"/>", "Aute deserunt consectetur voluptate eu enim. Magna officia minim et duis. Quis enim culpa deserunt cupidatat proident est aute culpa qui veniam dolore id pariatur. Dolor dolor do cupidatat labore officia excepteur reprehenderit aliqua anim.<img src=\"http://example.org/f922e8a6-6858/f922e8a6-6858\" height=\"1\" width=\"1\"/>", "Dolor occaecat eiusmod dolore ex excepteur. Aliqua nulla fugiat fugiat ex. Dolore irure ipsum sit excepteur laborum anim incididunt tempor. In culpa ut occaecat fugiat excepteur. Culpa duis adipisicing irure cillum. Dolore ipsum excepteur adipisicing quis enim qui consequat eiusmod cillum et sunt exercitation deserunt. Do laborum minim labore culpa officia est do nulla in excepteur irure excepteur irure.<img src=\"http://example.org/f38437e8-fc5e/f38437e8-fc5e\" height=\"1\" width=\"1\"/>", "Incididunt cupidatat deserunt nostrud dolor irure magna id. Tempor ullamco enim consectetur id qui elit sint occaecat aliquip ipsum. Laboris sit exercitation ut eu. Est elit aute culpa enim officia in eiusmod ullamco deserunt anim. Incididunt deserunt qui ullamco adipisicing enim eu proident fugiat cupidatat dolore veniam.<img src=\"http://example.org/55cdf187-75a4/55cdf187-75a4\" height=\"1\" width=\"1\"/>", "Pariatur reprehenderit elit ad laborum aute cupidatat laborum excepteur sint adipisicing et mollit mollit minim. Sint fugiat duis irure pariatur ad fugiat proident. Adipisicing deserunt in ut sunt. Dolor officia dolore ipsum ut eu duis do consequat ea velit et nostrud incididunt non.<img src=\"http://example.org/61711c9a-bb60/61711c9a-bb60\" height=\"1\" width=\"1\"/>", "Culpa eiusmod sint cupidatat veniam non et do irure incididunt eu dolor eu. Irure eu velit id sunt duis ullamco deserunt commodo consequat sit. Fugiat sit magna Lorem et reprehenderit consectetur labore culpa et. Veniam consequat pariatur consequat et velit consectetur fugiat ex consectetur. Officia adipisicing enim officia aute aliqua non ipsum proident incididunt aliquip sint. Aliquip aute in id sit proident occaecat ipsum.<img src=\"http://example.org/e6dfd5ca-fe18/e6dfd5ca-fe18\" height=\"1\" width=\"1\"/>", "Quis in non cupidatat tempor. Exercitation cupidatat ullamco aliqua voluptate id ad do eiusmod commodo sint pariatur. In voluptate excepteur dolore proident magna et et aliquip eiusmod esse laboris incididunt. Irure laboris proident dolore eiusmod fugiat reprehenderit. Culpa reprehenderit consequat pariatur duis qui Lorem deserunt proident.<img src=\"http://example.org/fa06e360-df1d/fa06e360-df1d\" height=\"1\" width=\"1\"/>", "Consectetur velit ea anim Lorem anim minim magna adipisicing nostrud proident. Occaecat pariatur ut excepteur eiusmod cupidatat. Exercitation laboris exercitation in voluptate eiusmod magna consequat occaecat eiusmod consectetur enim amet nostrud.<img src=\"http://example.org/d71b7f85-6476/d71b7f85-6476\" height=\"1\" width=\"1\"/>", "Et quis deserunt ea non ipsum quis et minim pariatur ad proident amet cupidatat. Occaecat consectetur id proident culpa commodo in irure aliquip incididunt incididunt proident cillum ad veniam. Proident occaecat ipsum deserunt sint est nulla dolore cupidatat amet commodo do enim. Consequat amet culpa nulla id culpa id elit aliquip amet dolore consectetur minim ad voluptate. Mollit sunt cillum laborum esse est velit. Id occaecat cupidatat nulla sunt cillum anim nostrud in.<img src=\"http://example.org/8d448ef2-86c0/8d448ef2-86c0\" height=\"1\" width=\"1\"/>", "Consectetur anim ex commodo ullamco labore fugiat ea ea laborum quis. Culpa dolore dolor ut id cillum. Consectetur et labore quis consectetur mollit et mollit pariatur veniam. Minim aliquip magna aute incididunt dolor amet quis. Laboris sint labore Lorem et enim. Et sunt sint enim et labore velit.<img src=\"http://example.org/33647027-3906/33647027-3906\" height=\"1\" width=\"1\"/>", "Consectetur adipisicing Lorem ipsum aute exercitation est. Magna aliqua quis ut est voluptate officia sit ea labore mollit veniam. Amet eu sunt irure cillum non laborum in exercitation enim ea minim aliqua in deserunt. Esse sunt esse eiusmod est aute dolore elit ex amet fugiat labore proident amet aliqua. Elit id id magna nisi magna ea eiusmod aute ut ea velit aliquip anim.<img src=\"http://example.org/f8d5ab84-775d/f8d5ab84-775d\" height=\"1\" width=\"1\"/>", "Nostrud exercitation incididunt ex quis proident esse labore in id reprehenderit culpa sit officia. Ipsum anim proident elit laborum in enim velit pariatur incididunt sit anim pariatur aute. Esse proident pariatur eiusmod enim sunt eu labore ad ut dolor aliquip occaecat enim. In sunt elit aliquip ea minim reprehenderit sint ea sunt excepteur. Consequat occaecat aute sint exercitation. Nulla nulla sint duis cillum cupidatat adipisicing et.<img src=\"http://example.org/ac3b396d-0d95/ac3b396d-0d95\" height=\"1\" width=\"1\"/>" };
    QString plainDescriptions[] = { "Minim qui aliquip adipisicing pariatur aliqua tempor. Amet fugiat labore eiusmod sit fugiat adipisicing reprehenderit ad cupidatat nisi eiusmod ut enim. Do sint nulla aliqua occaecat dolore sit esse laboris ad labore. Cillum labore incididunt aliqua commodo. Adipisicing et Lorem deserunt consequat velit. Est ipsum Lorem enim commodo sit esse eu cillum veniam qui labore.", "Consequat ut in voluptate qui magna esse veniam. Excepteur velit enim aliqua elit irure et aliquip velit. Mollit proident cupidatat aliquip dolor enim enim anim magna elit. In fugiat sint et id mollit.", "Ipsum reprehenderit aliquip veniam sint mollit deserunt ex ipsum. Eiusmod incididunt amet mollit eiusmod aliqua consectetur eu tempor qui ex occaecat tempor id cillum. Sit ad excepteur officia minim in. Deserunt dolor velit irure deserunt est consectetur labore pariatur cillum.", "Id voluptate qui officia occaecat enim proident ad. Esse irure ex mollit ad enim ipsum duis nisi do eu. Tempor duis esse sint occaecat qui sint deserunt consequat dolore tempor eiusmod ullamco aute. Ea non ea eiusmod adipisicing Lorem exercitation.", "Cillum enim anim aliquip sint. Esse nulla irure consectetur proident dolor consectetur qui. Do laboris eu qui in cillum. Cillum velit commodo quis occaecat elit ut cillum eu irure.", "Aute sunt officia labore ullamco laborum. Et voluptate ex dolore ut labore commodo dolor aute aliqua. Fugiat sunt officia aliquip occaecat exercitation sunt velit id ullamco pariatur. Esse aliquip nisi anim aliquip incididunt Lorem consectetur eu magna. Duis non quis minim tempor sit proident enim. Sit reprehenderit pariatur id veniam. Cupidatat ad commodo veniam minim occaecat deserunt.", "Adipisicing in anim velit do aliquip nisi aute. Cupidatat cupidatat ea est ipsum esse consectetur ea tempor incididunt culpa elit. Magna magna consequat nisi velit aliqua do. Non dolor eu incididunt id sit Lorem nulla. Fugiat elit minim irure deserunt officia quis tempor sint sint sunt mollit tempor proident do. Reprehenderit veniam do consequat cupidatat duis elit magna et enim sunt deserunt sunt. Qui laboris Lorem sit magna in commodo cillum.", "Officia esse ex tempor irure do ea in cupidatat minim nisi laborum dolor cillum. Mollit sit minim sunt irure reprehenderit esse. Exercitation occaecat sint magna ea sunt reprehenderit reprehenderit. Id eu ipsum incididunt consequat ut magna ea occaecat mollit qui aliqua. Minim elit quis ea nisi aliquip exercitation enim cillum non excepteur dolor duis.", "Mollit occaecat sunt qui cillum cupidatat magna adipisicing anim tempor quis sunt laboris mollit. Enim adipisicing qui culpa ullamco aliqua ad quis. Sunt laborum excepteur ad laboris dolor adipisicing labore labore occaecat. Qui consequat ea ut fugiat tempor excepteur cillum laboris minim laboris voluptate. Cupidatat reprehenderit cillum aliquip incididunt eiusmod. Cupidatat aute commodo ipsum sit aliquip quis excepteur in esse laboris velit cillum culpa fugiat. Do duis duis sit mollit duis non est.", "Aute deserunt consectetur voluptate eu enim. Magna officia minim et duis. Quis enim culpa deserunt cupidatat proident est aute culpa qui veniam dolore id pariatur. Dolor dolor do cupidatat labore officia excepteur reprehenderit aliqua anim.", "Dolor occaecat eiusmod dolore ex excepteur. Aliqua nulla fugiat fugiat ex. Dolore irure ipsum sit excepteur laborum anim incididunt tempor. In culpa ut occaecat fugiat excepteur. Culpa duis adipisicing irure cillum. Dolore ipsum excepteur adipisicing quis enim qui consequat eiusmod cillum et sunt exercitation deserunt. Do laborum minim labore culpa officia est do nulla in excepteur irure excepteur irure.", "Incididunt cupidatat deserunt nostrud dolor irure magna id. Tempor ullamco enim consectetur id qui elit sint occaecat aliquip ipsum. Laboris sit exercitation ut eu. Est elit aute culpa enim officia in eiusmod ullamco deserunt anim. Incididunt deserunt qui ullamco adipisicing enim eu proident fugiat cupidatat dolore veniam.", "Pariatur reprehenderit elit ad laborum aute cupidatat laborum excepteur sint adipisicing et mollit mollit minim. Sint fugiat duis irure pariatur ad fugiat proident. Adipisicing deserunt in ut sunt. Dolor officia dolore ipsum ut eu duis do consequat ea velit et nostrud incididunt non.", "Culpa eiusmod sint cupidatat veniam non et do irure incididunt eu dolor eu. Irure eu velit id sunt duis ullamco deserunt commodo consequat sit. Fugiat sit magna Lorem et reprehenderit consectetur labore culpa et. Veniam consequat pariatur consequat et velit consectetur fugiat ex consectetur. Officia adipisicing enim officia aute aliqua non ipsum proident incididunt aliquip sint. Aliquip aute in id sit proident occaecat ipsum.", "Quis in non cupidatat tempor. Exercitation cupidatat ullamco aliqua voluptate id ad do eiusmod commodo sint pariatur. In voluptate excepteur dolore proident magna et et aliquip eiusmod esse laboris incididunt. Irure laboris proident dolore eiusmod fugiat reprehenderit. Culpa reprehenderit consequat pariatur duis qui Lorem deserunt proident.", "Consectetur velit ea anim Lorem anim minim magna adipisicing nostrud proident. Occaecat pariatur ut excepteur eiusmod cupidatat. Exercitation laboris exercitation in voluptate eiusmod magna consequat occaecat eiusmod consectetur enim amet nostrud.", "Et quis deserunt ea non ipsum quis et minim pariatur ad proident amet cupidatat. Occaecat consectetur id proident culpa commodo in irure aliquip incididunt incididunt proident cillum ad veniam. Proident occaecat ipsum deserunt sint est nulla dolore cupidatat amet commodo do enim. Consequat amet culpa nulla id culpa id elit aliquip amet dolore consectetur minim ad voluptate. Mollit sunt cillum laborum esse est velit. Id occaecat cupidatat nulla sunt cillum anim nostrud in.", "Consectetur anim ex commodo ullamco labore fugiat ea ea laborum quis. Culpa dolore dolor ut id cillum. Consectetur et labore quis consectetur mollit et mollit pariatur veniam. Minim aliquip magna aute incididunt dolor amet quis. Laboris sint labore Lorem et enim. Et sunt sint enim et labore velit.", "Consectetur adipisicing Lorem ipsum aute exercitation est. Magna aliqua quis ut est voluptate officia sit ea labore mollit veniam. Amet eu sunt irure cillum non laborum in exercitation enim ea minim aliqua in deserunt. Esse sunt esse eiusmod est aute dolore elit ex amet fugiat labore proident amet aliqua. Elit id id magna nisi magna ea eiusmod aute ut ea velit aliquip anim.", "Nostrud exercitation incididunt ex quis proident esse labore in id reprehenderit culpa sit officia. Ipsum anim proident elit laborum in enim velit pariatur incididunt sit anim pariatur aute. Esse proident pariatur eiusmod enim sunt eu labore ad ut dolor aliquip occaecat enim. In sunt elit aliquip ea minim reprehenderit sint ea sunt excepteur. Consequat occaecat aute sint exercitation. Nulla nulla sint duis cillum cupidatat adipisicing et." };
    int index = 0;

    foreach (VNTRSSItem* rssItem, rssChannel->getRSSItems()) {
        QCOMPARE(rssItem->getDescription(), descriptions[index]);
        QCOMPARE(rssItem->getPlainDescription(), plainDescriptions[index++]);
    }
}

void UnitTests::testRSSSiteFooDate() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-foo.xml");
    QCOMPARE(rssChannel->getDate(), this->getSimpleDateFormatRSS("Thu, 13 Dec 2014 20:05:00 +0100"));
}

void UnitTests::testRSSSiteFooLink() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-foo.xml");
    QCOMPARE(rssChannel->getLink(), QUrl("http://example.foo/"));
}

void UnitTests::testRSSSiteFooImageInternet() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-foo.xml");
    QCOMPARE(rssChannel->getImageUrl(), QUrl("http://example.foo/test.png"));
    QCOMPARE(rssChannel->getImageFileType(), QString("png"));
}

void UnitTests::testRSSSiteFooLanguage() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-foo.xml");
    QCOMPARE(rssChannel->getLanguage(), QString("en-en"));
}

void UnitTests::testRSSSiteFooTitle() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-foo.xml");
    QCOMPARE(rssChannel->getTitle(), QString("Foo"));
    QCOMPARE(rssChannel->getPlainTitle(), QString("Foo"));
}

void UnitTests::testRSSSiteFooDescription() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-foo.xml");
    QCOMPARE(rssChannel->getDescription(), QString("Foo description"));
    QCOMPARE(rssChannel->getPlainDescription(), QString("Foo description"));
}

void UnitTests::testRSSSiteFooItemSize() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-foo.xml");
    QList<VNTRSSItem*> rssItems = rssChannel->getRSSItems();
    QCOMPARE(rssItems.size(), 12);
}

void UnitTests::testRSSSiteFooItemLink() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-foo.xml");
    QString links[] = { "http://example.foo/rss/7a8b6840-afdf-4fef-9ecd-55516087a7eb", "http://example.foo/rss/e8e24b27-f612-4faf-952d-fa01e1caca9e", "http://example.foo/rss/0b72e426-5aaf-4932-902a-9c58875af99e", "http://example.foo/rss/3e928962-da3d-4e88-ac91-67278bb5987d", "http://example.foo/rss/fb6492ce-7c24-49af-8b80-bf16822e6566", "http://example.foo/rss/7768c4d0-56c7-493a-b08f-952d78942f06", "http://example.foo/rss/772cd4f2-45ca-4b23-bc92-6c525a95dc1e", "http://example.foo/rss/e8e86ef2-ad02-4a7c-870c-3aed82094a8c", "http://example.foo/rss/5bd7cce6-5204-4179-b7ef-1f43cf00d535", "http://example.foo/rss/d3b7fc68-e15c-42bd-872f-dac595a6f7d3", "http://example.foo/rss/b8693832-325e-40d7-b363-66802c427ded", "http://example.foo/rss/bbe15f94-3e65-4f70-b18f-628536dc3ee0" };
    int index = 0;

    foreach (VNTRSSItem* rssItem, rssChannel->getRSSItems()) {
        QCOMPARE(rssItem->getLink(), QUrl(links[index++]));
    }
}

void UnitTests::testRSSSiteFooItemDate() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-foo.xml");
    QString dates[] = { "Thu, 13 Nov 2014 20:05:00 +0100", "Thu, 13 Nov 2014 19:41:00 +0100", "Thu, 13 Nov 2014 16:38:00 +0100", "Thu, 13 Nov 2014 15:45:00 +0100", "Thu, 13 Nov 2014 15:39:00 +0100", "Thu, 13 Nov 2014 15:00:00 +0100", "Thu, 13 Nov 2014 13:40:00 +0100", "Thu, 13 Nov 2014 11:33:00 +0100", "Thu, 13 Nov 2014 05:49:00 +0100", "Wed, 12 Nov 2014 19:32:00 +0100", "Wed, 12 Nov 2014 19:20:00 +0100", "Wed, 12 Nov 2014 17:03:00 +0100" };
    int index = 0;

    foreach (VNTRSSItem* rssItem, rssChannel->getRSSItems()) {
        QCOMPARE(rssItem->getDate(), this->getSimpleDateFormatRSS(dates[index++]));
    }
}

void UnitTests::testRSSSiteFooItemTitle() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-foo.xml");
    QString titles[] = { "dolor veniam in est veniam quis quis officia adipisicing dolore", "amet qui nulla quis pariatur laborum minim commodo mollit consectetur", "exercitation in culpa aute do ut anim labore reprehenderit labore", "reprehenderit amet dolore magna cillum pariatur esse officia sit enim", "esse incididunt occaecat proident esse officia reprehenderit eu officia incididunt", "irure amet aliquip labore et eu veniam culpa irure mollit", "ipsum veniam ut pariatur ex reprehenderit anim exercitation id labore", "eiusmod amet irure mollit ullamco excepteur et incididunt ut esse", "laboris aliqua ad dolore pariatur commodo occaecat fugiat ad velit", "quis qui veniam non cillum duis duis Lorem minim cillum", "consequat elit magna Lorem minim ut eu ullamco irure ullamco", "sint cupidatat pariatur sunt proident mollit duis dolor qui fugiat" };
    QString plainTitles[] = { "dolor veniam in est veniam quis quis officia adipisicing dolore", "amet qui nulla quis pariatur laborum minim commodo mollit consectetur", "exercitation in culpa aute do ut anim labore reprehenderit labore", "reprehenderit amet dolore magna cillum pariatur esse officia sit enim", "esse incididunt occaecat proident esse officia reprehenderit eu officia incididunt", "irure amet aliquip labore et eu veniam culpa irure mollit", "ipsum veniam ut pariatur ex reprehenderit anim exercitation id labore", "eiusmod amet irure mollit ullamco excepteur et incididunt ut esse", "laboris aliqua ad dolore pariatur commodo occaecat fugiat ad velit", "quis qui veniam non cillum duis duis Lorem minim cillum", "consequat elit magna Lorem minim ut eu ullamco irure ullamco", "sint cupidatat pariatur sunt proident mollit duis dolor qui fugiat" };
    int index = 0;

    foreach (VNTRSSItem* rssItem, rssChannel->getRSSItems()) {
        QCOMPARE(rssItem->getTitle(), titles[index]);
        QCOMPARE(rssItem->getPlainTitle(), plainTitles[index++]);
    }
}

void UnitTests::testRSSSiteFooItemImage() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-foo.xml");

    foreach (VNTRSSItem* rssItem, rssChannel->getRSSItems()) {
        QCOMPARE(rssItem->getImageUrl(), QUrl());
        QCOMPARE(rssItem->getImageFileType(), QString());
    }
}

void UnitTests::testRSSSiteFooItemDescription() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-site-foo.xml");
    QString descriptions[] = { "Cillum duis sint culpa velit nisi amet excepteur culpa dolore reprehenderit ipsum deserunt esse reprehenderit. Incididunt qui magna quis quis ad voluptate proident esse cupidatat reprehenderit irure esse. Commodo voluptate id velit anim. In id aliquip aliquip nulla minim ad sint ad. Reprehenderit et reprehenderit aute nisi quis do irure laborum voluptate aute dolore. Anim voluptate velit elit labore nisi officia.", "Do duis nisi Lorem culpa. Adipisicing labore consequat aute aliqua minim quis aliqua dolore exercitation ex magna aliqua exercitation incididunt. Et velit et minim ea excepteur dolor cillum excepteur duis voluptate laboris aliquip ut. Reprehenderit aute excepteur non consectetur.", "Ad eu eiusmod nisi occaecat. Fugiat cupidatat adipisicing duis ullamco officia voluptate aliqua sit nostrud tempor veniam eiusmod ipsum. Est aliqua ipsum nisi veniam elit ipsum velit. Labore deserunt consectetur qui sunt anim.", "Pariatur minim cillum et excepteur velit est aute tempor veniam enim officia excepteur. In in occaecat labore fugiat cupidatat amet. Est laborum exercitation culpa veniam esse aliquip officia quis ullamco elit do adipisicing et. Ipsum laborum amet sunt cupidatat aute tempor. Ullamco velit ad ut non sunt fugiat aute irure ullamco in. Deserunt minim Lorem esse fugiat consequat nisi consectetur.", "Et fugiat cupidatat quis deserunt qui nisi. Ullamco eiusmod ullamco quis laborum ut. Enim consectetur eu irure veniam eiusmod labore cupidatat cupidatat elit consectetur. Ea esse cupidatat nostrud anim mollit aliquip aute. Officia anim non enim cupidatat minim laboris sunt enim ipsum est.", "Et irure exercitation dolor veniam enim in aute ad adipisicing cillum. Do in qui anim excepteur ad nulla aute esse nulla dolor eu. Ad cupidatat in Lorem est ea dolore pariatur. Culpa enim cillum sit ut. Enim exercitation nostrud aliquip non duis adipisicing.", "Laboris aliquip amet id ipsum consectetur aute sint nulla dolore. Duis fugiat deserunt non consectetur nostrud esse incididunt velit. Labore officia reprehenderit ut aliquip sint nulla culpa laboris cupidatat qui. Reprehenderit ea irure deserunt ea dolor non labore incididunt anim non voluptate sint incididunt aute. Adipisicing esse ex incididunt proident laborum. Proident veniam occaecat minim et aute Lorem adipisicing sit exercitation amet quis. Deserunt irure in Lorem qui nostrud ut.", "Nisi id nulla magna qui id consequat pariatur enim consequat mollit et amet. Adipisicing proident occaecat non nisi sint veniam fugiat duis est aliqua velit. Ea proident esse qui occaecat deserunt est non esse duis sunt ex. Aute minim incididunt deserunt dolor dolore deserunt dolor occaecat. Anim sint nisi laboris do elit ex consectetur officia.", "Amet incididunt dolor aute laborum proident Lorem officia. Elit est adipisicing ea cupidatat nostrud dolor in magna ea veniam. Consectetur duis anim nisi aute excepteur consequat. Culpa esse est laboris mollit ut culpa Lorem magna. Proident et consectetur tempor nostrud dolore commodo veniam cupidatat.", "Enim reprehenderit ad voluptate mollit reprehenderit nulla minim sit consequat duis consequat. In nostrud nostrud commodo sit cillum proident id esse est consequat excepteur aliqua ipsum duis. Elit in adipisicing sit enim aliqua.", "Anim elit cupidatat ipsum ex est. Lorem ad veniam incididunt consequat officia anim. Ipsum aliquip adipisicing enim cupidatat sint cupidatat eiusmod aliqua ex minim.", "Culpa enim ullamco ullamco anim do do mollit aute elit non pariatur reprehenderit labore aliqua. Laboris dolor elit minim id esse amet tempor esse aute eu tempor voluptate mollit. Voluptate non nulla mollit cupidatat irure qui labore adipisicing ad dolor esse. Deserunt occaecat aliquip nulla reprehenderit in id culpa cillum ad dolor eu eiusmod aliqua. Deserunt mollit in ipsum mollit aliquip labore do ad aliqua cillum. Reprehenderit labore fugiat excepteur cupidatat enim enim velit ex cillum in labore. Magna aliqua esse pariatur pariatur proident labore occaecat." };
    QString plainDescriptions[] = { "Cillum duis sint culpa velit nisi amet excepteur culpa dolore reprehenderit ipsum deserunt esse reprehenderit. Incididunt qui magna quis quis ad voluptate proident esse cupidatat reprehenderit irure esse. Commodo voluptate id velit anim. In id aliquip aliquip nulla minim ad sint ad. Reprehenderit et reprehenderit aute nisi quis do irure laborum voluptate aute dolore. Anim voluptate velit elit labore nisi officia.", "Do duis nisi Lorem culpa. Adipisicing labore consequat aute aliqua minim quis aliqua dolore exercitation ex magna aliqua exercitation incididunt. Et velit et minim ea excepteur dolor cillum excepteur duis voluptate laboris aliquip ut. Reprehenderit aute excepteur non consectetur.", "Ad eu eiusmod nisi occaecat. Fugiat cupidatat adipisicing duis ullamco officia voluptate aliqua sit nostrud tempor veniam eiusmod ipsum. Est aliqua ipsum nisi veniam elit ipsum velit. Labore deserunt consectetur qui sunt anim.", "Pariatur minim cillum et excepteur velit est aute tempor veniam enim officia excepteur. In in occaecat labore fugiat cupidatat amet. Est laborum exercitation culpa veniam esse aliquip officia quis ullamco elit do adipisicing et. Ipsum laborum amet sunt cupidatat aute tempor. Ullamco velit ad ut non sunt fugiat aute irure ullamco in. Deserunt minim Lorem esse fugiat consequat nisi consectetur.", "Et fugiat cupidatat quis deserunt qui nisi. Ullamco eiusmod ullamco quis laborum ut. Enim consectetur eu irure veniam eiusmod labore cupidatat cupidatat elit consectetur. Ea esse cupidatat nostrud anim mollit aliquip aute. Officia anim non enim cupidatat minim laboris sunt enim ipsum est.", "Et irure exercitation dolor veniam enim in aute ad adipisicing cillum. Do in qui anim excepteur ad nulla aute esse nulla dolor eu. Ad cupidatat in Lorem est ea dolore pariatur. Culpa enim cillum sit ut. Enim exercitation nostrud aliquip non duis adipisicing.", "Laboris aliquip amet id ipsum consectetur aute sint nulla dolore. Duis fugiat deserunt non consectetur nostrud esse incididunt velit. Labore officia reprehenderit ut aliquip sint nulla culpa laboris cupidatat qui. Reprehenderit ea irure deserunt ea dolor non labore incididunt anim non voluptate sint incididunt aute. Adipisicing esse ex incididunt proident laborum. Proident veniam occaecat minim et aute Lorem adipisicing sit exercitation amet quis. Deserunt irure in Lorem qui nostrud ut.", "Nisi id nulla magna qui id consequat pariatur enim consequat mollit et amet. Adipisicing proident occaecat non nisi sint veniam fugiat duis est aliqua velit. Ea proident esse qui occaecat deserunt est non esse duis sunt ex. Aute minim incididunt deserunt dolor dolore deserunt dolor occaecat. Anim sint nisi laboris do elit ex consectetur officia.", "Amet incididunt dolor aute laborum proident Lorem officia. Elit est adipisicing ea cupidatat nostrud dolor in magna ea veniam. Consectetur duis anim nisi aute excepteur consequat. Culpa esse est laboris mollit ut culpa Lorem magna. Proident et consectetur tempor nostrud dolore commodo veniam cupidatat.", "Enim reprehenderit ad voluptate mollit reprehenderit nulla minim sit consequat duis consequat. In nostrud nostrud commodo sit cillum proident id esse est consequat excepteur aliqua ipsum duis. Elit in adipisicing sit enim aliqua.", "Anim elit cupidatat ipsum ex est. Lorem ad veniam incididunt consequat officia anim. Ipsum aliquip adipisicing enim cupidatat sint cupidatat eiusmod aliqua ex minim.", "Culpa enim ullamco ullamco anim do do mollit aute elit non pariatur reprehenderit labore aliqua. Laboris dolor elit minim id esse amet tempor esse aute eu tempor voluptate mollit. Voluptate non nulla mollit cupidatat irure qui labore adipisicing ad dolor esse. Deserunt occaecat aliquip nulla reprehenderit in id culpa cillum ad dolor eu eiusmod aliqua. Deserunt mollit in ipsum mollit aliquip labore do ad aliqua cillum. Reprehenderit labore fugiat excepteur cupidatat enim enim velit ex cillum in labore. Magna aliqua esse pariatur pariatur proident labore occaecat." };
    int index = 0;

    foreach (VNTRSSItem* rssItem, rssChannel->getRSSItems()) {
        QCOMPARE(rssItem->getDescription(), descriptions[index]);
        QCOMPARE(rssItem->getPlainDescription(), plainDescriptions[index++]);
    }
}

void UnitTests::testAtomChannelDateSet() {
    VNTRSSChannel* rssChannelAtom = this->getRSSChannel("atom-channel-date-set.xml");
    QCOMPARE(rssChannelAtom->getDate(), this->getSimpleDateFormatAtom("2014-11-1320:05:00"));
}

void UnitTests::testRSSChannelDateSet() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-channel-date-set.xml");
    QCOMPARE(rssChannel->getDate(), this->getSimpleDateFormatRSS("Thu, 13 Nov 2014 20:05:00 +0100"));
}

void UnitTests::testAtomChannelDateEmpty() {
    VNTRSSChannel* rssChannelAtom = this->getRSSChannel("atom-channel-date-empty.xml");
    QCOMPARE(rssChannelAtom->getDate(), QDateTime());
}

void UnitTests::testRSSChannelDateEmpty() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-channel-date-empty.xml");
    QCOMPARE(rssChannel->getDate(), QDateTime());
}

void UnitTests::testAtomChannelDateNull() {
    VNTRSSChannel* rssChannelAtom = this->getRSSChannel("atom-channel-date-null.xml");
    QCOMPARE(rssChannelAtom->getDate(), QDateTime());
}

void UnitTests::testRSSChannelDateNull() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-channel-date-null.xml");
    QCOMPARE(rssChannel->getDate(), QDateTime());
}

void UnitTests::testAtomChannelLinkNull() {
    VNTRSSChannel* rssChannelAtom = this->getRSSChannel("atom-channel-link-null.xml");
    QCOMPARE(rssChannelAtom->getLink(), QUrl());
}

void UnitTests::testRSSChannelLinkNull() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-channel-link-null.xml");
    QCOMPARE(rssChannel->getLink(), QUrl());
}

void UnitTests::testAtomChannelLinkSet() {
    VNTRSSChannel* rssChannelAtom = this->getRSSChannel("atom-channel-link-set.xml");
    QCOMPARE(rssChannelAtom->getLink(), LINK);
}

void UnitTests::testAtomChannelLinkTwiceSet() {
    VNTRSSChannel* rssChannelAtom = this->getRSSChannel("atom-channel-link-twice-set.xml");
    QCOMPARE(rssChannelAtom->getLink(), LINK);
}

void UnitTests::testRSSChannelLinkSet() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-channel-link-set.xml");
    QCOMPARE(rssChannel->getLink(), LINK);
}

void UnitTests::testAtomChannelLinkEmpty() {
    VNTRSSChannel* rssChannelAtom = this->getRSSChannel("atom-channel-link-empty.xml");
    QCOMPARE(rssChannelAtom->getLink(), QUrl(""));
}

void UnitTests::testRSSChannelLinkEmpty() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-channel-link-empty.xml");
    QCOMPARE(rssChannel->getLink(), QUrl(""));
}

void UnitTests::testAtomChannelTitleNull() {
    VNTRSSChannel* rssChannelAtom = this->getRSSChannel("atom-channel-title-null.xml");
    QCOMPARE(rssChannelAtom->getTitle(), QString());
}

void UnitTests::testRSSChannelTitleNull() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-channel-title-null.xml");
    QCOMPARE(rssChannel->getTitle(), QString());
}

void UnitTests::testAtomChannelTitlePlainSet() {
    VNTRSSChannel* rssChannelAtom = this->getRSSChannel("atom-channel-title-plain-set.xml");
    QCOMPARE(rssChannelAtom->getPlainTitle(), PLAIN_TITLE);
}

void UnitTests::testRSSChannelTitlePlainSet() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-channel-title-plain-set.xml");
    QCOMPARE(rssChannel->getPlainTitle(), PLAIN_TITLE);
}

void UnitTests::testAtomChannelTitleSet() {
    VNTRSSChannel* rssChannelAtom = this->getRSSChannel("atom-channel-title-set.xml");
    QCOMPARE(rssChannelAtom->getTitle(), TITLE);
}

void UnitTests::testRSSChannelTitleSet() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-channel-title-set.xml");
    QCOMPARE(rssChannel->getTitle(), TITLE);
}

void UnitTests::testAtomChannelTitleEmpty() {
    VNTRSSChannel* rssChannelAtom = this->getRSSChannel("atom-channel-title-empty.xml");
    QCOMPARE(rssChannelAtom->getTitle(), QString(""));
}

void UnitTests::testRSSChannelTitleEmpty() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-channel-title-empty.xml");
    QCOMPARE(rssChannel->getTitle(), QString(""));
}

void UnitTests::testAtomChannelDescriptionNull() {
    VNTRSSChannel* rssChannelAtom = this->getRSSChannel("atom-channel-description-null.xml");
    QCOMPARE(rssChannelAtom->getDescription(), QString());
}

void UnitTests::testRSSChannelDescriptionNull() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-channel-description-null.xml");
    QCOMPARE(rssChannel->getDescription(), QString());
}

void UnitTests::testAtomChannelDescriptionSet() {
    VNTRSSChannel* rssChannelAtom = this->getRSSChannel("atom-channel-description-set.xml");
    QCOMPARE(rssChannelAtom->getDescription(), CHANNEL_DESCRIPTION);
}

void UnitTests::testRSSChannelDescriptionSet() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-channel-description-set.xml");
    QCOMPARE(rssChannel->getDescription(), CHANNEL_DESCRIPTION);
}

void UnitTests::testAtomChannelDescriptionPlainSet() {
    VNTRSSChannel* rssChannelAtom = this->getRSSChannel("atom-channel-description-plain-set.xml");
    QCOMPARE(rssChannelAtom->getPlainDescription(), CHANNEL_DESCRIPTION);
}

void UnitTests::testRSSChannelDescriptionPlainSet() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-channel-description-plain-set.xml");
    QCOMPARE(rssChannel->getPlainDescription(), CHANNEL_DESCRIPTION);
}

void UnitTests::testAtomChannelDescriptionEmpty() {
    VNTRSSChannel* rssChannelAtom = this->getRSSChannel("atom-channel-description-empty.xml");
    QCOMPARE(rssChannelAtom->getDescription(), QString(""));
}

void UnitTests::testRSSChannelDescriptionEmpty() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-channel-description-empty.xml");
    QCOMPARE(rssChannel->getDescription(), QString(""));
}

void UnitTests::testAtomChannelImageNull() {
    VNTRSSChannel* rssChannelAtom = this->getRSSChannel("atom-channel-image-null.xml");
    QCOMPARE(rssChannelAtom->getImageUrl(), QUrl());
}

void UnitTests::testRSSChannelImageNull() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-channel-image-null.xml");
    QCOMPARE(rssChannel->getImageUrl(), QUrl());
}

void UnitTests::testAtomChannelImageSet() {
    VNTRSSChannel* rssChannelAtom = this->getRSSChannel("atom-channel-image-set.xml");
    QCOMPARE(rssChannelAtom->getImageUrl(), IMAGE);
    QCOMPARE(rssChannelAtom->getImageFileType(), IMAGE_FILE_TYPE);
}

void UnitTests::testRSSChannelImageSet() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-channel-image-set.xml");
    QCOMPARE(rssChannel->getImageUrl(), IMAGE);
    QCOMPARE(rssChannel->getImageFileType(), IMAGE_FILE_TYPE);
}

void UnitTests::testAtomChannelImageEmpty() {
    VNTRSSChannel* rssChannelAtom = this->getRSSChannel("atom-channel-image-empty.xml");
    QCOMPARE(rssChannelAtom->getImageUrl(), QUrl(""));
}

void UnitTests::testRSSChannelImageEmpty() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-channel-image-empty.xml");
    QCOMPARE(rssChannel->getImageUrl(), QUrl(""));
}

void UnitTests::testAtomChannelLanguageSet() {
    VNTRSSChannel* rssChannelAtom = this->getRSSChannel("atom-channel-language-set.xml");
    QCOMPARE(rssChannelAtom->getLanguage(), LANGUAGE);
}

void UnitTests::testRSSChannelLanguageSet() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-channel-language-set.xml");
    QCOMPARE(rssChannel->getLanguage(), LANGUAGE);
}

void UnitTests::testAtomChannelLanguageEmpty() {
    VNTRSSChannel* rssChannelAtom = this->getRSSChannel("atom-channel-language-empty.xml");
    QCOMPARE(rssChannelAtom->getLanguage(), QString(""));
}

void UnitTests::testRSSChannelLanguageEmpty() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-channel-language-empty.xml");
    QCOMPARE(rssChannel->getLanguage(), QString(""));
}

void UnitTests::testAtomChannelLanguageNull() {
    VNTRSSChannel* rssChannelAtom = this->getRSSChannel("atom-channel-language-null.xml");
    QCOMPARE(rssChannelAtom->getLanguage(), QString());
}

void UnitTests::testRSSChannelLanguageNull() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-channel-language-null.xml");
    QCOMPARE(rssChannel->getLanguage(), QString());
}

void UnitTests::testAtomChannelItemSet() {
    VNTRSSChannel* rssChannelAtom = this->getRSSChannel("atom-item-set.xml");
    QCOMPARE(rssChannelAtom->getRSSItems().size(), 1);
}

void UnitTests::testRSSChannelItemSet() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-item-set.xml");
    QCOMPARE(rssChannel->getRSSItems().size(), 1);
}

void UnitTests::testAtomChannelItemEmpty() {
    VNTRSSChannel* rssChannelAtom = this->getRSSChannel("atom-item-empty.xml");
    QCOMPARE(rssChannelAtom->getRSSItems().size(), 1);
}

void UnitTests::testRSSChannelItemEmpty() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-item-empty.xml");
    QCOMPARE(rssChannel->getRSSItems().size(), 1);
}

void UnitTests::testAtomChannelItemNull() {
    VNTRSSChannel* rssChannelAtom = this->getRSSChannel("atom-item-null.xml");
    QCOMPARE(rssChannelAtom->getRSSItems().size(), 0);
}

void UnitTests::testRSSChannelItemNull() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("rss-item-null.xml");
    QCOMPARE(rssChannel->getRSSItems().size(), 0);
}

void UnitTests::testAtomItemDateSet() {
    VNTRSSItem* rssItemAtom = this->getFirstRSSItem("atom-item-date-set.xml");
    QCOMPARE(rssItemAtom->getDate(), this->getSimpleDateFormatAtom("2014-11-1320:05:00"));
}

void UnitTests::testRSSItemDateSet() {
    VNTRSSItem* rssItem = this->getFirstRSSItem("rss-item-date-set.xml");
    QCOMPARE(rssItem->getDate(), this->getSimpleDateFormatRSS("Thu, 13 Nov 2014 20:05:00 +0100"));
}

void UnitTests::testAtomItemDateEmpty() {
    VNTRSSItem* rssItemAtom = this->getFirstRSSItem("atom-item-date-empty.xml");
    QCOMPARE(rssItemAtom->getDate(), QDateTime());
}

void UnitTests::testRSSItemDateEmpty() {
    VNTRSSItem* rssItem = this->getFirstRSSItem("rss-item-date-empty.xml");
    QCOMPARE(rssItem->getDate(), QDateTime());
}

void UnitTests::testAtomItemDateNull() {
    VNTRSSItem* rssItemAtom = this->getFirstRSSItem("atom-item-date-null.xml");
    QCOMPARE(rssItemAtom->getDate(), QDateTime());
}

void UnitTests::testRSSItemDateNull() {
    VNTRSSItem* rssItem = this->getFirstRSSItem("rss-item-date-null.xml");
    QCOMPARE(rssItem->getDate(), QDateTime());
}

void UnitTests::testAtomItemLinkSet() {
    VNTRSSItem* rssItemAtom = this->getFirstRSSItem("atom-item-link-set.xml");
    QCOMPARE(rssItemAtom->getLink(), LINK);
}

void UnitTests::testRSSItemLinkSet() {
    VNTRSSItem* rssItem = this->getFirstRSSItem("rss-item-link-set.xml");
    QCOMPARE(rssItem->getLink(), LINK);
}

void UnitTests::testAtomItemLinkEmpty() {
    VNTRSSItem* rssItemAtom = this->getFirstRSSItem("atom-item-link-empty.xml");
    QCOMPARE(rssItemAtom->getLink(), QUrl(""));
}

void UnitTests::testRSSItemLinkEmpty() {
    VNTRSSItem* rssItem = this->getFirstRSSItem("rss-item-link-empty.xml");
    QCOMPARE(rssItem->getLink(), QUrl(""));
}

void UnitTests::testAtomItemLinkNull() {
    VNTRSSItem* rssItemAtom = this->getFirstRSSItem("atom-item-link-null.xml");
    QCOMPARE(rssItemAtom->getLink(), QUrl());
}

void UnitTests::testRSSItemLinkNull() {
    VNTRSSItem* rssItem = this->getFirstRSSItem("rss-item-link-null.xml");
    QCOMPARE(rssItem->getLink(), QUrl());
}

void UnitTests::testAtomItemTitleSet() {
    VNTRSSItem* rssItemAtom = this->getFirstRSSItem("atom-item-title-set.xml");
    QCOMPARE(rssItemAtom->getTitle(), TITLE);
}

void UnitTests::testRSSItemTitleSet() {
    VNTRSSItem* rssItem = this->getFirstRSSItem("rss-item-title-set.xml");
    QCOMPARE(rssItem->getTitle(), TITLE);
}

void UnitTests::testAtomItemTitlePlainSet() {
    VNTRSSItem* rssItemAtom = this->getFirstRSSItem("atom-item-title-plain-set.xml");
    QCOMPARE(rssItemAtom->getPlainTitle(), PLAIN_TITLE);
}

void UnitTests::testRSSItemTitlePlainSet() {
    VNTRSSItem* rssItem = this->getFirstRSSItem("rss-item-title-plain-set.xml");
    QCOMPARE(rssItem->getPlainTitle(), PLAIN_TITLE);
}

void UnitTests::testAtomItemTitleEmpty() {
    VNTRSSItem* rssItemAtom = this->getFirstRSSItem("atom-item-title-empty.xml");
    QCOMPARE(rssItemAtom->getTitle(), QString(""));
}

void UnitTests::testRSSItemTitleEmpty() {
    VNTRSSItem* rssItem = this->getFirstRSSItem("rss-item-title-empty.xml");
    QCOMPARE(rssItem->getTitle(), QString(""));
}

void UnitTests::testAtomItemTitleNull() {
    VNTRSSItem* rssItemAtom = this->getFirstRSSItem("atom-item-title-null.xml");
    QCOMPARE(rssItemAtom->getTitle(), QString());
}

void UnitTests::testRSSItemTitleNull() {
    VNTRSSItem* rssItem = this->getFirstRSSItem("rss-item-title-null.xml");
    QCOMPARE(rssItem->getTitle(), QString());
}

void UnitTests::testAtomItemDescriptionSet() {
    VNTRSSItem* rssItemAtom = this->getFirstRSSItem("atom-item-description-set.xml");
    QCOMPARE(rssItemAtom->getDescription(), ITEM_DESCRIPTION);
}

void UnitTests::testRSSItemDescriptionSet() {
    VNTRSSItem* rssItem = this->getFirstRSSItem("rss-item-description-set.xml");
    QCOMPARE(rssItem->getDescription(), ITEM_DESCRIPTION);
}

void UnitTests::testAtomItemDescriptionPlainSet() {
    VNTRSSItem* rssItemAtom = this->getFirstRSSItem("atom-item-description-plain-set.xml");
    QCOMPARE(rssItemAtom->getPlainDescription(), ITEM_DESCRIPTION_PLAIN);
}

void UnitTests::testRSSItemDescriptionPlainSet() {
    VNTRSSItem* rssItem = this->getFirstRSSItem("rss-item-description-plain-set.xml");
    QCOMPARE(rssItem->getPlainDescription(), ITEM_DESCRIPTION_PLAIN);
}

void UnitTests::testAtomItemDescriptionEmpty() {
    VNTRSSItem* rssItemAtom = this->getFirstRSSItem("atom-item-description-empty.xml");
    QCOMPARE(rssItemAtom->getDescription(), QString(""));
}

void UnitTests::testRSSItemDescriptionEmpty() {
    VNTRSSItem* rssItem = this->getFirstRSSItem("rss-item-description-empty.xml");
    QCOMPARE(rssItem->getDescription(), QString(""));
}

void UnitTests::testAtomItemDescriptionNull() {
    VNTRSSItem* rssItemAtom = this->getFirstRSSItem("atom-item-description-null.xml");
    QCOMPARE(rssItemAtom->getDescription(), QString());
}

void UnitTests::testRSSItemDescriptionNull() {
    VNTRSSItem* rssItem = this->getFirstRSSItem("rss-item-description-null.xml");
    QCOMPARE(rssItem->getDescription(), QString());
}

void UnitTests::testAtomItemDescriptionImageSet() {
    VNTRSSItem* rssItemAtom = this->getFirstRSSItem("atom-item-description-image-set.xml");
    QCOMPARE(rssItemAtom->getImageUrl(), IMAGE);
    QCOMPARE(rssItemAtom->getImageFileType(), IMAGE_FILE_TYPE);
}

void UnitTests::testRSSItemDescriptionImageSet() {
    VNTRSSItem* rssItem = this->getFirstRSSItem("rss-item-description-image-set.xml");
    QCOMPARE(rssItem->getImageUrl(), IMAGE);
    QCOMPARE(rssItem->getImageFileType(), IMAGE_FILE_TYPE);
}

void UnitTests::testAtomItemDescriptionImageEmpty() {
    VNTRSSItem* rssItemAtom = this->getFirstRSSItem("atom-item-description-image-empty.xml");
    QCOMPARE(rssItemAtom->getImageUrl(), QUrl());
    QCOMPARE(rssItemAtom->getImageFileType(), QString());
}

void UnitTests::testRSSItemDescriptionImageEmpty() {
    VNTRSSItem* rssItem = this->getFirstRSSItem("rss-item-description-image-empty.xml");
    QCOMPARE(rssItem->getImageUrl(), QUrl());
    QCOMPARE(rssItem->getImageFileType(), QString());
}

void UnitTests::testAtomItemDescriptionImageNull() {
    VNTRSSItem* rssItemAtom = this->getFirstRSSItem("atom-item-description-image-null.xml");
    QCOMPARE(rssItemAtom->getImageUrl(), QUrl());
    QCOMPARE(rssItemAtom->getImageFileType(), QString());
}

void UnitTests::testRSSItemDescriptionImageNull() {
    VNTRSSItem* rssItem = this->getFirstRSSItem("rss-item-description-image-null.xml");
    QCOMPARE(rssItem->getImageUrl(), QUrl());
    QCOMPARE(rssItem->getImageFileType(), QString());
}

void UnitTests::testAtomItemImageSet() {
    VNTRSSItem* rssItemAtom = this->getFirstRSSItem("atom-item-image-set.xml");
    QCOMPARE(rssItemAtom->getImageUrl(), IMAGE);
    QCOMPARE(rssItemAtom->getImageFileType(), IMAGE_FILE_TYPE);
}

void UnitTests::testRSSItemImageSet() {
    VNTRSSItem* rssItem = this->getFirstRSSItem("rss-item-image-set.xml");
    QCOMPARE(rssItem->getImageUrl(), IMAGE);
    QCOMPARE(rssItem->getImageFileType(), IMAGE_FILE_TYPE);
}

void UnitTests::testAtomItemImageEmpty() {
    VNTRSSItem* rssItemAtom = this->getFirstRSSItem("atom-item-image-empty.xml");
    QCOMPARE(rssItemAtom->getImageUrl(), QUrl(""));
}

void UnitTests::testRSSItemImageEmpty() {
    VNTRSSItem* rssItem = this->getFirstRSSItem("rss-item-image-empty.xml");
    QCOMPARE(rssItem->getImageUrl(), QUrl(""));
}

void UnitTests::testAtomItemImageNull() {
    VNTRSSItem* rssItemAtom = this->getFirstRSSItem("atom-item-image-null.xml");
    QCOMPARE(rssItemAtom->getImageUrl(), QUrl());
}

void UnitTests::testRSSItemImageNull() {
    VNTRSSItem* rssItem = this->getFirstRSSItem("rss-item-image-null.xml");
    QCOMPARE(rssItem->getImageUrl(), QUrl());
}

void UnitTests::testRSSItemImageClutterSet() {
    VNTRSSItem* rssItem = this->getFirstRSSItem("rss-item-image-clutter-set.xml");
    QCOMPARE(rssItem->getImageUrl(), IMAGE);
    QCOMPARE(rssItem->getImageFileType(), IMAGE_FILE_TYPE);
}

void UnitTests::testRSSItemImageClutterEmpty() {
    VNTRSSItem* rssItem = this->getFirstRSSItem("rss-item-image-clutter-empty.xml");
    QCOMPARE(rssItem->getImageUrl(), QUrl(""));
}

void UnitTests::testRSSItemImageClutterNull() {
    VNTRSSItem* rssItem = this->getFirstRSSItem("rss-item-image-clutter-null.xml");
    QCOMPARE(rssItem->getImageUrl(), QUrl());
}

void UnitTests::testAtomItemImageJPEGSet() {
    VNTRSSItem* rssItem = this->getFirstRSSItem("atom-item-image-jpeg-set.xml");
    QCOMPARE(rssItem->getImageUrl(), QUrl("http://vanniktech.de/img/nav/speedreader.png"));
    QCOMPARE(rssItem->getImageFileType(), QString("png"));
}

void UnitTests::testAtomItemImageJPEGNull() {
    VNTRSSItem* rssItem = this->getFirstRSSItem("atom-item-image-jpeg-null.xml");
    QCOMPARE(rssItem->getImageUrl(), QUrl(""));
}

void UnitTests::testAtomItemImageJPEGEmpty() {
    VNTRSSItem* rssItem = this->getFirstRSSItem("atom-item-image-jpeg-empty.xml");
    QCOMPARE(rssItem->getImageUrl(), QUrl(""));
}

void UnitTests::testAtomItemImagePNGSet() {
    VNTRSSItem* rssItem = this->getFirstRSSItem("atom-item-image-png-set.xml");
    QCOMPARE(rssItem->getImageUrl(), QUrl("http://vanniktech.de/img/nav/speedreader.png"));
    QCOMPARE(rssItem->getImageFileType(), QString("png"));
}

void UnitTests::testAtomItemImagePNGNull() {
    VNTRSSItem* rssItem = this->getFirstRSSItem("atom-item-image-png-null.xml");
    QCOMPARE(rssItem->getImageUrl(), QUrl(""));
}

void UnitTests::testAtomItemImagePNGEmpty() {
    VNTRSSItem* rssItem = this->getFirstRSSItem("atom-item-image-png-empty.xml");
    QCOMPARE(rssItem->getImageUrl(), QUrl(""));
}

void UnitTests::testVanniktechAtom() {
    VNTRSSChannel* rssChannel = this->getRSSChannel(QUrl("http://tests.vanniktech.de/atom.xml"));

    QCOMPARE(rssChannel->getRSSSite(), QUrl("http://tests.vanniktech.de/atom.xml"));
    QCOMPARE(rssChannel->getLink(), QUrl("http://vanniktech.de/"));
    QCOMPARE(rssChannel->getTitle(), QString("Vanniktech"));
    QCOMPARE(rssChannel->getPlainTitle(), QString("Vanniktech"));
    QCOMPARE(rssChannel->getDescription(), QString("Vanniktech Test Atom Feed"));
    QCOMPARE(rssChannel->getPlainDescription(), QString("Vanniktech Test Atom Feed"));
    QCOMPARE(rssChannel->getDate(), this->getSimpleDateFormatAtom("2014-11-2319:10:03"));

    QList<VNTRSSItem*> rssItems = rssChannel->getRSSItems();

    QCOMPARE(rssItems.size(), 2);

    QCOMPARE(rssItems.at(0)->getLink(), QUrl("http://vanniktech.de/SpeedReader"));
    QCOMPARE(rssItems.at(0)->getTitle(), QString("SpeedReader"));
    QCOMPARE(rssItems.at(0)->getPlainTitle(), QString("SpeedReader"));
    QCOMPARE(rssItems.at(0)->getDescription(), QString("This is a summary for SpeedReader"));
    QCOMPARE(rssItems.at(0)->getPlainDescription(), QString("This is a summary for SpeedReader"));
    QCOMPARE(rssItems.at(0)->getDate(), this->getSimpleDateFormatAtom("2014-11-2319:10:03"));

    QCOMPARE(rssItems.at(1)->getLink(), QUrl("http://vanniktech.de/ShapeSliding"));
    QCOMPARE(rssItems.at(1)->getTitle(), QString("ShapeSliding"));
    QCOMPARE(rssItems.at(1)->getPlainTitle(), QString("ShapeSliding"));
    QCOMPARE(rssItems.at(1)->getDescription(), QString("This is a summary for ShapeSliding"));
    QCOMPARE(rssItems.at(1)->getPlainDescription(), QString("This is a summary for ShapeSliding"));
    QCOMPARE(rssItems.at(1)->getDate(), this->getSimpleDateFormatAtom("2014-11-2319:10:03"));
}

void UnitTests::testVanniktechAtomRedirect() {
    VNTRSSChannel* rssChannel = this->getRSSChannel(QUrl("http://tests.vanniktech.de/atom_redirect.php"));

    QCOMPARE(rssChannel->getRSSSite(), QUrl("http://tests.vanniktech.de/atom_redirect.php"));
    QCOMPARE(rssChannel->getLink(), QUrl("http://vanniktech.de/"));
    QCOMPARE(rssChannel->getTitle(), QString("Vanniktech"));
    QCOMPARE(rssChannel->getPlainTitle(), QString("Vanniktech"));
    QCOMPARE(rssChannel->getDescription(), QString("Vanniktech Test Atom Feed"));
    QCOMPARE(rssChannel->getPlainDescription(), QString("Vanniktech Test Atom Feed"));
    QCOMPARE(rssChannel->getDate(), this->getSimpleDateFormatAtom("2014-11-2319:10:03"));

    QList<VNTRSSItem*> rssItems = rssChannel->getRSSItems();

    QCOMPARE(rssItems.size(), 2);

    QCOMPARE(rssItems.at(0)->getLink(), QUrl("http://vanniktech.de/SpeedReader"));
    QCOMPARE(rssItems.at(0)->getTitle(), QString("SpeedReader"));
    QCOMPARE(rssItems.at(0)->getPlainTitle(), QString("SpeedReader"));
    QCOMPARE(rssItems.at(0)->getDescription(), QString("This is a summary for SpeedReader"));
    QCOMPARE(rssItems.at(0)->getPlainDescription(), QString("This is a summary for SpeedReader"));
    QCOMPARE(rssItems.at(0)->getDate(), this->getSimpleDateFormatAtom("2014-11-2319:10:03"));

    QCOMPARE(rssItems.at(1)->getLink(), QUrl("http://vanniktech.de/ShapeSliding"));
    QCOMPARE(rssItems.at(1)->getTitle(), QString("ShapeSliding"));
    QCOMPARE(rssItems.at(1)->getPlainTitle(), QString("ShapeSliding"));
    QCOMPARE(rssItems.at(1)->getDescription(), QString("This is a summary for ShapeSliding"));
    QCOMPARE(rssItems.at(1)->getPlainDescription(), QString("This is a summary for ShapeSliding"));
    QCOMPARE(rssItems.at(1)->getDate(), this->getSimpleDateFormatAtom("2014-11-2319:10:03"));

}

void UnitTests::testVanniktechRSS() {
    VNTRSSChannel* rssChannel = this->getRSSChannel(QUrl("http://tests.vanniktech.de/rss.xml"));

    QCOMPARE(rssChannel->getRSSSite(), QUrl("http://tests.vanniktech.de/rss.xml"));
    QCOMPARE(rssChannel->getLink(), QUrl("http://vanniktech.de/"));
    QCOMPARE(rssChannel->getTitle(), QString("Vanniktech"));
    QCOMPARE(rssChannel->getPlainTitle(), QString("Vanniktech"));
    QCOMPARE(rssChannel->getDescription(), QString("Vanniktech Test RSS Feed"));
    QCOMPARE(rssChannel->getPlainDescription(), QString("Vanniktech Test RSS Feed"));
    QCOMPARE(rssChannel->getDate(), this->getSimpleDateFormatRSS("Sun, 23 Nov 2014 19:10:03 +0100"));

    QList<VNTRSSItem*> rssItems = rssChannel->getRSSItems();

    QCOMPARE(rssItems.size(), 2);

    QCOMPARE(rssItems.at(0)->getLink(), QUrl("http://vanniktech.de/SpeedReader"));
    QCOMPARE(rssItems.at(0)->getTitle(), QString("SpeedReader"));
    QCOMPARE(rssItems.at(0)->getPlainTitle(), QString("SpeedReader"));
    QCOMPARE(rssItems.at(0)->getDescription(), QString("This is a summary for SpeedReader"));
    QCOMPARE(rssItems.at(0)->getPlainDescription(), QString("This is a summary for SpeedReader"));
    QCOMPARE(rssItems.at(0)->getDate(), this->getSimpleDateFormatRSS("Sun, 23 Nov 2014 19:10:03 +0100"));

    QCOMPARE(rssItems.at(1)->getLink(), QUrl("http://vanniktech.de/ShapeSliding"));
    QCOMPARE(rssItems.at(1)->getTitle(), QString("ShapeSliding"));
    QCOMPARE(rssItems.at(1)->getPlainTitle(), QString("ShapeSliding"));
    QCOMPARE(rssItems.at(1)->getDescription(), QString("This is a summary for ShapeSliding"));
    QCOMPARE(rssItems.at(1)->getPlainDescription(), QString("This is a summary for ShapeSliding"));
    QCOMPARE(rssItems.at(1)->getDate(), this->getSimpleDateFormatRSS("Sun, 23 Nov 2014 19:10:03 +0100"));
}

void UnitTests::testVanniktechRSSRedirect() {
    VNTRSSChannel* rssChannel = this->getRSSChannel(QUrl("http://tests.vanniktech.de/rss_redirect.php"));

    QCOMPARE(rssChannel->getRSSSite(), QUrl("http://tests.vanniktech.de/rss_redirect.php"));
    QCOMPARE(rssChannel->getLink(), QUrl("http://vanniktech.de/"));
    QCOMPARE(rssChannel->getTitle(), QString("Vanniktech"));
    QCOMPARE(rssChannel->getPlainTitle(), QString("Vanniktech"));
    QCOMPARE(rssChannel->getDescription(), QString("Vanniktech Test RSS Feed"));
    QCOMPARE(rssChannel->getPlainDescription(), QString("Vanniktech Test RSS Feed"));
    QCOMPARE(rssChannel->getDate(), this->getSimpleDateFormatRSS("Sun, 23 Nov 2014 19:10:03 +0100"));

    QList<VNTRSSItem*> rssItems = rssChannel->getRSSItems();

    QCOMPARE(rssItems.size(), 2);

    QCOMPARE(rssItems.at(0)->getLink(), QUrl("http://vanniktech.de/SpeedReader"));
    QCOMPARE(rssItems.at(0)->getTitle(), QString("SpeedReader"));
    QCOMPARE(rssItems.at(0)->getPlainTitle(), QString("SpeedReader"));
    QCOMPARE(rssItems.at(0)->getDescription(), QString("This is a summary for SpeedReader"));
    QCOMPARE(rssItems.at(0)->getPlainDescription(), QString("This is a summary for SpeedReader"));
    QCOMPARE(rssItems.at(0)->getDate(), this->getSimpleDateFormatRSS("Sun, 23 Nov 2014 19:10:03 +0100"));

    QCOMPARE(rssItems.at(1)->getLink(), QUrl("http://vanniktech.de/ShapeSliding"));
    QCOMPARE(rssItems.at(1)->getTitle(), QString("ShapeSliding"));
    QCOMPARE(rssItems.at(1)->getPlainTitle(), QString("ShapeSliding"));
    QCOMPARE(rssItems.at(1)->getDescription(), QString("This is a summary for ShapeSliding"));
    QCOMPARE(rssItems.at(1)->getPlainDescription(), QString("This is a summary for ShapeSliding"));
    QCOMPARE(rssItems.at(1)->getDate(), this->getSimpleDateFormatRSS("Sun, 23 Nov 2014 19:10:03 +0100"));
}

void UnitTests::testVanniktechLiveEN() {
    VNTRSSChannel* rssChannel = this->getRSSChannel(QUrl("http://vanniktech.de/RSS/en"));

    QCOMPARE(rssChannel->getRSSSite(), QUrl("http://vanniktech.de/RSS/en"));
    QCOMPARE(rssChannel->getLink(), QUrl("www.vanniktech.de"));
    QCOMPARE(rssChannel->getTitle(), QString("Vanniktech"));
    QCOMPARE(rssChannel->getPlainTitle(), QString("Vanniktech"));
    QCOMPARE(rssChannel->getDescription(), QString("Vanniktech"));
    QCOMPARE(rssChannel->getPlainDescription(), QString("Vanniktech"));

    const QList<VNTRSSItem*> rssItems = rssChannel->getRSSItems();

    QVERIFY(rssItems.size() > 0);

    for (const VNTRSSItem* rssItem : rssItems) {
        QVERIFY(!rssItem->getDescription().isEmpty());
        QVERIFY(!rssItem->getTitle().isEmpty());
        QVERIFY(rssItem->getLink().isValid());
        QVERIFY(rssItem->getDate().isValid());
    }
}

void UnitTests::testVanniktechLiveDE() {
    VNTRSSChannel* rssChannel = this->getRSSChannel(QUrl("http://vanniktech.de/RSS/de"));

    QCOMPARE(rssChannel->getRSSSite(), QUrl("http://vanniktech.de/RSS/de"));
    QCOMPARE(rssChannel->getLink(), QUrl("www.vanniktech.de"));
    QCOMPARE(rssChannel->getTitle(), QString("Vanniktech"));
    QCOMPARE(rssChannel->getPlainTitle(), QString("Vanniktech"));
    QCOMPARE(rssChannel->getDescription(), QString("Vanniktech"));
    QCOMPARE(rssChannel->getPlainDescription(), QString("Vanniktech"));

    const QList<VNTRSSItem*> rssItems = rssChannel->getRSSItems();

    QVERIFY(rssItems.size() > 0);

    for (const VNTRSSItem* rssItem : rssItems) {
        QVERIFY(!rssItem->getDescription().isEmpty());
        QVERIFY(!rssItem->getTitle().isEmpty());
        QVERIFY(rssItem->getLink().isValid());
        QVERIFY(rssItem->getDate().isValid());
    }
}

void UnitTests::testInvalidFeed() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("invalid-feed.xml");
    QCOMPARE(rssChannel->hasError(), true);
    // TODO
}

void UnitTests::testInvalidXML() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("invalid-xml.xml");
    QCOMPARE(rssChannel->hasError(), true);
    // TODO
}

void UnitTests::testInvalidResonseEmpty() {
    VNTRSSChannel* rssChannel = this->getRSSChannel("invalid-response-empty.xml");
    QCOMPARE(rssChannel->hasError(), true);
    // TODO
}

VNTRSSChannel* UnitTests::getRSSChannel(const QString &fileName) {
    #ifdef Q_OS_MAC
        QFile file("../../../../UnitTests/assets/" + fileName);
    #else
        QFile file("../UnitTests/assets/" + fileName);
    #endif

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << QString("Could not find file ../UnitTests/assets/" + fileName);
    }

    VNTRSSReader* rssReader = new VNTRSSReader(this);
    return rssReader->parseData(fileName, file.readAll());
}

VNTRSSChannel* UnitTests::getRSSChannel(const QUrl &url) {
    VNTRSSReader* rssReader = new VNTRSSReader(this);
    QSignalSpy spy(rssReader, SIGNAL(loadedRSS(QList<VNTRSSChannel*>)));
    rssReader->load(url);

    QTest::qWait(500);

    return spy.takeFirst().at(0).value<QList<VNTRSSChannel*> >().at(0);
}

VNTRSSItem* UnitTests::getFirstRSSItem(const QString &fileName) {
    return this->getRSSChannel(fileName)->getRSSItems().at(0);
}

QDateTime UnitTests::getSimpleDateFormatAtom(const QString &date) {
    return QDateTime::fromString(date, "yyyy-MM-ddHH:mm:ss");
}

QDateTime UnitTests::getSimpleDateFormatRSS(const QString &date) {
    QString formattedDate = date.mid(5).mid(0, 20);
    formattedDate = formattedDate.replace("Jan", "01"); formattedDate = formattedDate.replace("Feb", "02"); formattedDate = formattedDate.replace("Mar", "03"); formattedDate = formattedDate.replace("Apr", "04"); formattedDate = formattedDate.replace("May", "05"); formattedDate = formattedDate.replace("Jun", "06"); formattedDate = formattedDate.replace("Jul", "07"); formattedDate = formattedDate.replace("Aug", "08"); formattedDate = formattedDate.replace("Sep", "09"); formattedDate = formattedDate.replace("Oct", "10"); formattedDate = formattedDate.replace("Nov", "11"); formattedDate = formattedDate.replace("Dez", "12");

    return QDateTime::fromString(formattedDate, "dd MM yyyy hh:mm:ss");
}

QTEST_MAIN(UnitTests)
#include "unittests.moc"
