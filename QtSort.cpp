#include "QtSort.h"
#include <QtCore/QtMath>
#include <QtCore/QDebug>
#include <QGridLayout>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QCategoryAxis>
#include  "Sorting.h"


QT_CHARTS_USE_NAMESPACE

ChartWidget::ChartWidget(QWidget *parent) :
	QWidget(parent), sort_time_{nullptr}

{

	sort_time_ = new SortTime;
	int i = 0;
	const int max_val = pow(10, 4);
	const int step = pow(10, 2);

    QChart *chartA = new QChart;
    QChartView *chartView1 = new QChartView(chartA);
    chartView1->setRenderHint(QPainter::Antialiasing);
    chartView1->setMaximumSize(500, 500);
	chartA->setTitle("random numbers");

	QChart *chartB = new QChart;
    QChartView *chartView2 = new QChartView(chartB);
    chartView2->setRenderHint(QPainter::Antialiasing);
    chartView2->setMaximumSize(500, 500);
    chartB->setTitle("increasing numbers");

	QChart *chartC = new QChart;
    QChartView *chartView3 = new QChartView(chartC);
    chartView3->setRenderHint(QPainter::Antialiasing);
    chartView3->setMaximumSize(500, 500);
    chartC->setTitle("decreasing numbers");

	QChart *chartA2 = new QChart;
    QChartView *chartView4 = new QChartView(chartA2);
    chartView4->setRenderHint(QPainter::Antialiasing);
    chartView4->setMaximumSize(500, 500);
    chartA2->setTitle("random numbers");

	QChart *chartB2 = new QChart;
	QChartView *chartView5 = new QChartView(chartB2);
	chartView5->setRenderHint(QPainter::Antialiasing);
	chartView5->setMaximumSize(500, 500);
	chartB2->setTitle("increasing numbers");

	QChart *chartC2 = new QChart;
	QChartView *chartView6 = new QChartView(chartC2);
	chartView6->setRenderHint(QPainter::Antialiasing);
	chartView6->setMaximumSize(500, 500);
	chartC2->setTitle("decreasing numbers");
	//3.1a//////////////////////////////////////////////////////////////////////////////

	QScatterSeries *TreeSortA = new QScatterSeries();
	TreeSortA->setName("TreeSort");
	TreeSortA->setMarkerSize(10);
	QScatterSeries *QuickSortA = new QScatterSeries();
	QuickSortA->setName("QuickSort");
	QuickSortA->setMarkerSize(10);
	auto time_tree_1_result = sort_time_->TimeTree1(nullptr);
	auto time_quick_1_result = sort_time_->TimeQuick1(nullptr);
	for (int n = 0; n <= max_val; n += step) {
		*TreeSortA << QPointF(n , time_tree_1_result[i]);
		*QuickSortA << QPointF(n, time_quick_1_result[i]);

		i++;
	}
	
	chartA->addSeries(TreeSortA);
	chartA->addSeries(QuickSortA);

	QFont labelsFont;
	labelsFont.setPixelSize(15);

	QValueAxis *axisX = new QValueAxis();
	axisX->setTitleText("number of elements in array");
	axisX->setLabelFormat("%i");
	chartA->addAxis(axisX, Qt::AlignBottom);
	TreeSortA->attachAxis(axisX);
	//QuickSortA->attachAxis(axisX);
	QValueAxis *axisY = new QValueAxis();
	axisY->setTitleText("time");
	axisY->setLabelFormat("%g");
	chartA->addAxis(axisY, Qt::AlignLeft);
	TreeSortA->attachAxis(axisY);
	QuickSortA->attachAxis(axisY);


	//3.1b//////////////////////////////////////////////////////////////////////////////
	
	i = 0;
	
	QScatterSeries *TreeSortB = new QScatterSeries();
	TreeSortB->setName("TreeSort");
	TreeSortB->setMarkerSize(10);
	QScatterSeries *QuickSortB = new QScatterSeries();
	QuickSortB->setName("QuickSort");
	QuickSortB->setMarkerSize(10);
	auto time_tree_2_result = sort_time_->TimeTree2(nullptr);
	auto time_quick_2_result = sort_time_->TimeQuick2(nullptr);
	for (int n = 0; n <= max_val; n += step) {
		*TreeSortB << QPointF(n, time_tree_2_result[i]);
		*QuickSortB << QPointF(n, time_quick_2_result[i]);

		i++;
	}

	chartB->addSeries(TreeSortB);
	chartB->addSeries(QuickSortB);

	QFont labelsFont1;
	labelsFont1.setPixelSize(15);

	QValueAxis *axisX2 = new QValueAxis();
	axisX2->setTitleText("number of elements in array");
	axisX2->setLabelFormat("%i");
	chartB->addAxis(axisX2, Qt::AlignBottom);
	TreeSortB->attachAxis(axisX2);
	//QuickSortB->attachAxis(axisX2);
	QValueAxis *axisY2 = new QValueAxis();
	axisY2->setTitleText("time");
	axisY2->setLabelFormat("%g");
	chartB->addAxis(axisY2, Qt::AlignLeft);
	TreeSortB->attachAxis(axisY2);
	QuickSortB->attachAxis(axisY2);

	//3.1c//////////////////////////////////////////////////////////////////////////////
	
	i = 0;

	QScatterSeries *TreeSortC = new QScatterSeries();
	TreeSortC->setName("TreeSort");
	TreeSortC->setMarkerSize(10);
	QScatterSeries *QuickSortC = new QScatterSeries();
	QuickSortC->setName("QuickSort");
	QuickSortC->setMarkerSize(10);
	auto time_tree_3_result = sort_time_->TimeTree3(nullptr);
	auto time_quick_3_result = sort_time_->TimeQuick3(nullptr);
	for (int n = 0; n <= max_val; n += step) {
		*TreeSortC << QPointF(n, time_tree_3_result[i]);
		*QuickSortC << QPointF(n, time_quick_3_result[i]);

		i++;
	}

	chartC->addSeries(TreeSortC);
	chartC->addSeries(QuickSortC);

	QFont labelsFont2;
	labelsFont2.setPixelSize(15);

	QValueAxis *axisX3 = new QValueAxis();
	axisX3->setTitleText("number of elements in array");
	axisX3->setLabelFormat("%i");
	chartC->addAxis(axisX3, Qt::AlignBottom);
	TreeSortC->attachAxis(axisX3);
	//QuickSortC->attachAxis(axisX3);
	QValueAxis *axisY3 = new QValueAxis();
	axisY3->setTitleText("time");
	axisY3->setLabelFormat("%g");
	chartC->addAxis(axisY3, Qt::AlignLeft);
	TreeSortC->attachAxis(axisY3);
	QuickSortC->attachAxis(axisY3);

//3.2a////////////////////////////////////////////////////////////////////////////////
	
	i = 0;
	
	QScatterSeries *TreeSortA2 = new QScatterSeries();
	TreeSortA2->setName("TreeSort");
	TreeSortA2->setMarkerSize(10);
	QScatterSeries *QuickSortA2 = new QScatterSeries();
	QuickSortA2->setName("QuickSort");
	QuickSortA2->setMarkerSize(10);
	auto time_tree_4_result = sort_time_->TimeTree4(nullptr);
	auto time_quick_4_result = sort_time_->TimeQuick4(nullptr);
	for (int n = 1; n <= 100; n ++ ) {
		*TreeSortA2 << QPointF(n, time_tree_4_result[i]);
		*QuickSortA2 << QPointF(n, time_quick_4_result[i]);

		i++;
	}

	chartA2->addSeries(TreeSortA2);
	chartA2->addSeries(QuickSortA2);

	QFont labelsFont3;
	labelsFont3.setPixelSize(15);

	QValueAxis *axisX4 = new QValueAxis();
	axisX4->setTitleText("range of numbers in array");
	axisX4->setLabelFormat("%i");
	chartA2->addAxis(axisX4, Qt::AlignBottom);
	TreeSortA2->attachAxis(axisX4);
	//QuickSortA2->attachAxis(axisX4);
	QValueAxis *axisY4 = new QValueAxis();
	axisY4->setTitleText("time");
	axisY4->setLabelFormat("%g");
	chartA2->addAxis(axisY4, Qt::AlignLeft);
	TreeSortA2->attachAxis(axisY4);
	QuickSortA2->attachAxis(axisY4);

	//3.2b////////////////////////////////////////////////////////////////////////////////

	i = 0;

	QScatterSeries *TreeSortB2 = new QScatterSeries();
	TreeSortB2->setName("TreeSort");
	TreeSortB2->setMarkerSize(10);
	QScatterSeries *QuickSortB2 = new QScatterSeries();
	QuickSortB2->setName("QuickSort");
	QuickSortB2->setMarkerSize(10);
	auto time_tree_5_result = sort_time_->TimeTree5(nullptr);
	auto time_quick_5_result = sort_time_->TimeQuick5(nullptr);
	for (int n = 1; n <= 100; n++) {
		*TreeSortB2 << QPointF(n, time_tree_5_result[i]);
		*QuickSortB2 << QPointF(n, time_quick_5_result[i]);

		i++;
	}

	chartB2->addSeries(TreeSortB2);
	chartB2->addSeries(QuickSortB2);

	QFont labelsFont4;
	labelsFont4.setPixelSize(15);

	QValueAxis *axisX5 = new QValueAxis();
	axisX5->setTitleText("range of numbers in array");
	axisX5->setLabelFormat("%i");
	chartB2->addAxis(axisX5, Qt::AlignBottom);
	TreeSortB2->attachAxis(axisX5);
	//QuickSortB2->attachAxis(axisX5);
	QValueAxis *axisY5 = new QValueAxis();
	axisY5->setTitleText("time");
	axisY5->setLabelFormat("%g");
	chartB2->addAxis(axisY5, Qt::AlignLeft);
	TreeSortB2->attachAxis(axisY5);
	QuickSortB2->attachAxis(axisY5);

	//3.2c////////////////////////////////////////////////////////////////////////////////

	i = 0;

	QScatterSeries *TreeSortC2 = new QScatterSeries();
	TreeSortC2->setName("TreeSort");
	TreeSortC2->setMarkerSize(10);
	QScatterSeries *QuickSortC2 = new QScatterSeries();
	QuickSortC2->setName("QuickSort");
	QuickSortC2->setMarkerSize(10);
	auto time_tree_6_result = sort_time_->TimeTree6(nullptr);
	auto time_quick_6_result = sort_time_->TimeQuick6(nullptr);
	for (int n = 1; n <= 100; n++) {
		*TreeSortC2 << QPointF(n, time_tree_6_result[i]);
		*QuickSortC2 << QPointF(n, time_quick_6_result[i]);

		i++;
	}

	chartC2->addSeries(TreeSortC2);
	chartC2->addSeries(QuickSortC2);

	QFont labelsFont5;
	labelsFont5.setPixelSize(15);

	QValueAxis *axisX6 = new QValueAxis();
	axisX6->setTitleText("range of numbers in array");
	axisX6->setLabelFormat("%i");
	chartC2->addAxis(axisX6, Qt::AlignBottom);
	TreeSortC2->attachAxis(axisX6);
	//QuickSortC2->attachAxis(axisX6);
	QValueAxis *axisY6 = new QValueAxis();
	axisY6->setTitleText("time");
	axisY6->setLabelFormat("%g");
	chartC2->addAxis(axisY6, Qt::AlignLeft);
	TreeSortC2->attachAxis(axisY6);
	QuickSortC2->attachAxis(axisY6);


	//////////////////////////////////////////////////////////////////////////////////////
	QGridLayout *mainLayout = new QGridLayout;
	mainLayout->addWidget(chartView1, 1, 0);
	mainLayout->addWidget(chartView2, 1, 1);
	mainLayout->addWidget(chartView3, 1, 2);
	mainLayout->addWidget(chartView4, 2, 0);
	mainLayout->addWidget(chartView5, 2, 1);
	mainLayout->addWidget(chartView6, 2, 2);
	setLayout(mainLayout);
}

ChartWidget::~ChartWidget()
{
	if (sort_time_ != nullptr) {
		delete sort_time_;
	}
	
}
