#include <TfTest/TfTest>
#include "helpers/applicationhelper.h"

class TestHelper : public QObject
{
    Q_OBJECT
private slots:
    void testTid_data();
    void testTid();
};

void TestHelper::testTid_data()
{
    QTest::addColumn<QString>("tid1");
    QTest::addColumn<QString>("tid2");
    //QString s = csrfVal();

    for (int i = 0; i < 10; ++i) {
        QString tid1 = tId();
        QString tid2 = tId();
        QString row = tid1 + "<-->" + tid2;
        QTest::newRow(row.toLatin1().data()) << tid1 << tid2;
    }

}

void TestHelper::testTid()
{

    QFETCH(QString, tid1);
    QFETCH(QString, tid2);

    QVERIFY2(!tid1.isEmpty(), "tid1 should not empty.");
    QVERIFY2(!tid2.isEmpty(), "tid2 should not empty.");
    QVERIFY2(tid1 != tid2, "tid1 should not equal tid2.");

}

TF_TEST_SQLLESS_MAIN(TestHelper)
#include "helper.moc"
