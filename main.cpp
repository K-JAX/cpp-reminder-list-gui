#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QObject>
#include <QDebug>


int initWindow(int argc, char *argv[]){
  QApplication app(argc, argv);

  QWidget window;
  window.resize(250, 150);
  window.setWindowTitle("Reminder App");

  QVBoxLayout *layout = new QVBoxLayout();

  QPushButton *button = new QPushButton("Click Me");

  // Add buttons to the layout
  layout->addWidget(button);

  window.setLayout(layout);

  QObject::connect(button, &QPushButton::clicked, [](){
      qDebug("Button was clicked");
  });

  window.show();

  return app.exec();
}

int main(int argc, char *argv[]) {
  return initWindow(argc, argv);
}
