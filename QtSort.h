#ifndef CHARTVIEW_H
#define CHARTVIEW_H

#include <QtWidgets/QWidget>
#include <QtCharts/QChartGlobal>
#include <QtCharts/QScatterSeries>

class SortTime;

QT_CHARTS_BEGIN_NAMESPACE
class QChartView;
class QChart;
QT_CHARTS_END_NAMESPACE




class ChartWidget : public QWidget
{
	Q_OBJECT

public:
	ChartWidget() = delete;
	explicit ChartWidget(QWidget *parent = 0);
	~ChartWidget();

private Q_SLOTS:


private:
	SortTime *sort_time_;
};


#endif // CHARTVIEW_H