#include "Charts.h"

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QPieSeries>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChartView>
#include <QtCharts/QChartGlobal>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

Charts::Charts(QWidget *parent)
    : QMainWindow(parent)
{
    // 创建折线图系列
    QLineSeries *lineSeries = new QLineSeries();
    lineSeries->append(0, 6);
    lineSeries->append(2, 4);
    lineSeries->append(3, 8);
    lineSeries->append(7, 4);
    lineSeries->append(10, 5);
    lineSeries->setName("折线图");

    // 创建柱状图系列
    QBarSet *set0 = new QBarSet("Jane");
    QBarSet *set1 = new QBarSet("John");
    QBarSet *set2 = new QBarSet("Axel");
    QBarSet *set3 = new QBarSet("Mary");
    QBarSet *set4 = new QBarSet("Samantha");

    *set0 << 1 << 2 << 3 << 4 << 5 << 6;
    *set1 << 5 << 0 << 0 << 4 << 0 << 7;
    *set2 << 3 << 5 << 8 << 13 << 8 << 5;
    *set3 << 5 << 6 << 7 << 3 << 4 << 5;
    *set4 << 9 << 7 << 5 << 3 << 1 << 2;

    QBarSeries *barSeries = new QBarSeries();
    barSeries->append(set0);
    barSeries->append(set1);
    barSeries->append(set2);
    barSeries->append(set3);
    barSeries->append(set4);
    barSeries->setName("柱状图");

    // 创建饼图系列
    QPieSeries *pieSeries = new QPieSeries();
    pieSeries->append("Jane", 1);
    pieSeries->append("John", 2);
    pieSeries->append("Axel", 3);
    pieSeries->append("Mary", 4);
    pieSeries->append("Samantha", 5);
    pieSeries->setName("饼图");

    // 创建散点图系列
    QScatterSeries *scatterSeries = new QScatterSeries();
    scatterSeries->append(1, 1);
    scatterSeries->append(2, 4);
    scatterSeries->append(3, 9);
    scatterSeries->append(4, 16);
    scatterSeries->append(5, 25);
    scatterSeries->setName("散点图");

    // 创建图表对象
    QChart *lineChart = new QChart();
    lineChart->addSeries(lineSeries);
    lineChart->setTitle("折线图");
    lineChart->legend()->setVisible(true);              // 显示图例
    lineChart->legend()->setAlignment(Qt::AlignBottom); // 图例对齐方式
    lineChart->setBackgroundBrush(QBrush(QColor(240, 240, 240)));
    lineChart->setPlotAreaBackgroundBrush(QBrush(QColor(255, 255, 255)));
    lineChart->setPlotAreaBackgroundVisible(true);
    lineChart->setTheme(QChart::ChartThemeLight);          // 主题
    lineChart->setAnimationOptions(QChart::AllAnimations); // 动画效果

    QChart *barChart = new QChart();
    barChart->addSeries(barSeries);
    barChart->setTitle("柱状图");
    barChart->legend()->setVisible(true);
    barChart->legend()->setAlignment(Qt::AlignBottom);
    barChart->setBackgroundBrush(QBrush(QColor(240, 240, 240)));
    barChart->setPlotAreaBackgroundBrush(QBrush(QColor(255, 255, 255)));
    barChart->setPlotAreaBackgroundVisible(true);
    barChart->setTheme(QChart::ChartThemeQt);
    barChart->setAnimationOptions(QChart::AllAnimations);

    QChart *pieChart = new QChart();
    pieChart->addSeries(pieSeries);
    pieChart->setTitle("饼图");
    pieChart->legend()->setVisible(true);
    pieChart->legend()->setAlignment(Qt::AlignBottom);
    pieChart->setBackgroundBrush(QBrush(QColor(240, 240, 240)));
    pieChart->setPlotAreaBackgroundBrush(QBrush(QColor(255, 255, 255)));
    pieChart->setPlotAreaBackgroundVisible(true);
    pieChart->setTheme(QChart::ChartThemeDark);
    pieChart->setAnimationOptions(QChart::AllAnimations);

    QChart *scatterChart = new QChart();
    scatterChart->addSeries(scatterSeries);
    scatterChart->setTitle("散点图");
    scatterChart->legend()->setVisible(true);
    scatterChart->legend()->setAlignment(Qt::AlignBottom);
    scatterChart->setBackgroundBrush(QBrush(QColor(240, 240, 240)));
    scatterChart->setPlotAreaBackgroundBrush(QBrush(QColor(255, 255, 255)));
    scatterChart->setPlotAreaBackgroundVisible(true);
    scatterChart->setTheme(QChart::ChartThemeHighContrast);
    scatterChart->setAnimationOptions(QChart::AllAnimations);

    // 创建图表视图
    QChartView *lineChartView = new QChartView(lineChart); // `lineChartView`将负责管理`lineChart`的显示
    lineChartView->setRenderHint(QPainter::Antialiasing);  // 设置抗锯齿渲染

    QChartView *barChartView = new QChartView(barChart);
    barChartView->setRenderHint(QPainter::Antialiasing);

    QChartView *pieChartView = new QChartView(pieChart);
    pieChartView->setRenderHint(QPainter::Antialiasing);

    QChartView *scatterChartView = new QChartView(scatterChart);
    scatterChartView->setRenderHint(QPainter::Antialiasing);

    // 创建布局并添加图表视图
    QWidget *centralWidget = new QWidget(this);
    QGridLayout *layout = new QGridLayout(centralWidget);
    layout->addWidget(lineChartView, 0, 0);
    layout->addWidget(barChartView, 0, 1);
    layout->addWidget(pieChartView, 1, 0);
    layout->addWidget(scatterChartView, 1, 1);

    // 设置主窗口
    setCentralWidget(centralWidget);
}

Charts::~Charts()
{
}