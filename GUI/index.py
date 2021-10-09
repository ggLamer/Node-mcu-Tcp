# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'main.ui'
#
# Created by: PyQt5 UI code generator 5.15.4
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


import threading
from PyQt5 import QtCore, QtGui, QtWidgets
import requests
from threading import Thread
import sys
import socket
    
import keyboard

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(549, 357)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.temp = QtWidgets.QLabel(self.centralwidget)
        self.temp.setGeometry(QtCore.QRect(20, 20, 111, 31))
        self.temp.setObjectName("temp")
        self.humi = QtWidgets.QLabel(self.centralwidget)
        self.humi.setEnabled(True)
        self.humi.setGeometry(QtCore.QRect(20, 60, 111, 31))
        self.humi.setObjectName("humi")
        self.prec = QtWidgets.QLabel(self.centralwidget)
        self.prec.setGeometry(QtCore.QRect(20, 100, 111, 31))
        self.prec.setObjectName("prec")
        self.connetc = QtWidgets.QPushButton(self.centralwidget)
        self.connetc.setGeometry(QtCore.QRect(360, 0, 191, 71))
        self.connetc.setStyleSheet("  text-decoration: none;\n"
"  display: inline-block;\n"
"  color: black;\n"
"  padding: 20px 30px;\n"
"  margin: 10px 20px;\n"
"  border-radius: 10px;\n"
"  font-family: \'Montserrat\', sans-serif;\n"
"  text-transform: uppercase;\n"
"  letter-spacing: 2px;\n"
"  background: qlineargradient(spread:pad, x1:0.920364, y1:0.585, x2:0.125, y2:0.6875, stop:0.403409 rgba(167, 185, 255, 255), stop:0.994318 rgba(131, 189, 232, 255));\n"
"  box-shadow: 0 0 20px rgba(0, 0, 0, .1);")
        self.connetc.setObjectName("connetc")
        self.connetc.clicked.connect(self.conne)
        self.x_left = QtWidgets.QPushButton(self.centralwidget)
        self.x_left.setGeometry(QtCore.QRect(170, 70, 191, 71))
        self.x_left.clicked.connect(self.x_l)
        self.x_left.setStyleSheet("  text-decoration: none;\n"
"  display: inline-block;\n"
"  color: black;\n"
"  padding: 20px 30px;\n"
"  margin: 10px 20px;\n"
"  border-radius: 10px;\n"
"  font-family: \'Montserrat\', sans-serif;\n"
"  text-transform: uppercase;\n"
"  letter-spacing: 2px;\n"
"  background: qlineargradient(spread:pad, x1:0.920364, y1:0.585, x2:0.125, y2:0.6875, stop:0.403409 rgba(167, 185, 255, 255), stop:0.994318 rgba(131, 189, 232, 255));\n"
"  box-shadow: 0 0 20px rgba(0, 0, 0, .1);")
        self.x_left.setObjectName("x_left")
        self.x_right = QtWidgets.QPushButton(self.centralwidget)
        self.x_right.setGeometry(QtCore.QRect(170, 0, 191, 71))
        self.x_right.clicked.connect(self.x_r)
        self.x_right.setStyleSheet("  text-decoration: none;\n"
"  display: inline-block;\n"
"  color: black;\n"
"  padding: 20px 30px;\n"
"  margin: 10px 20px;\n"
"  border-radius: 10px;\n"
"  font-family: \'Montserrat\', sans-serif;\n"
"  text-transform: uppercase;\n"
"  letter-spacing: 2px;\n"
"  background: qlineargradient(spread:pad, x1:0.920364, y1:0.585, x2:0.125, y2:0.6875, stop:0.403409 rgba(167, 185, 255, 255), stop:0.994318 rgba(131, 189, 232, 255));\n"
"  box-shadow: 0 0 20px rgba(0, 0, 0, .1);")
        self.x_right.setObjectName("x_right")
        self.Acceleration = QtWidgets.QLabel(self.centralwidget)
        self.Acceleration.setGeometry(QtCore.QRect(20, 190, 111, 31))
        self.Acceleration.setObjectName("Acceleration")
        self.Acceleration_X = QtWidgets.QLabel(self.centralwidget)
        self.Acceleration_X.setGeometry(QtCore.QRect(20, 240, 111, 31))
        self.Acceleration_X.setObjectName("Acceleration_X")
        self.Acceleration_Y = QtWidgets.QLabel(self.centralwidget)
        self.Acceleration_Y.setGeometry(QtCore.QRect(20, 280, 111, 31))
        self.Acceleration_Y.setObjectName("Acceleration_Y")
        self.Acceleration_Z = QtWidgets.QLabel(self.centralwidget)
        self.Acceleration_Z.setGeometry(QtCore.QRect(20, 320, 111, 31))
        self.Acceleration_Z.setObjectName("Acceleration_Z")
        self.Rotation = QtWidgets.QLabel(self.centralwidget)
        self.Rotation.setGeometry(QtCore.QRect(140, 190, 111, 31))
        self.Rotation.setObjectName("Rotation")
        self.Rotation_X = QtWidgets.QLabel(self.centralwidget)
        self.Rotation_X.setGeometry(QtCore.QRect(140, 240, 111, 31))
        self.Rotation_X.setObjectName("Rotation_X")
        self.Rotation_Y = QtWidgets.QLabel(self.centralwidget)
        self.Rotation_Y.setGeometry(QtCore.QRect(140, 280, 111, 31))
        self.Rotation_Y.setObjectName("Rotation_Y")
        self.Rotation_Z = QtWidgets.QLabel(self.centralwidget)
        self.Rotation_Z.setGeometry(QtCore.QRect(140, 320, 111, 31))
        self.Rotation_Z.setObjectName("Rotation_Z")
        self.busvoltage = QtWidgets.QLabel(self.centralwidget)
        self.busvoltage.setGeometry(QtCore.QRect(260, 190, 181, 31))
        self.busvoltage.setObjectName("busvoltage")
        self.power_mW = QtWidgets.QLabel(self.centralwidget)
        self.power_mW.setGeometry(QtCore.QRect(260, 230, 181, 31))
        self.power_mW.setObjectName("power_mW")
        self.current_mA = QtWidgets.QLabel(self.centralwidget)
        self.current_mA.setGeometry(QtCore.QRect(260, 270, 181, 31))
        self.current_mA.setObjectName("current_mA")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 549, 21))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.temp.setText(_translate("MainWindow", "Temp"))
        self.humi.setText(_translate("MainWindow", "Humidity"))
        self.prec.setText(_translate("MainWindow", "Precc"))
        self.connetc.setText(_translate("MainWindow", "Connect"))
        self.x_left.setText(_translate("MainWindow", "X left"))
        self.x_right.setText(_translate("MainWindow", "X Right"))
        self.Acceleration.setText(_translate("MainWindow", "Acceleration:"))
        self.Acceleration_X.setText(_translate("MainWindow", "Acceleration X: "))
        self.Acceleration_Y.setText(_translate("MainWindow", "Acceleration Y:"))
        self.Acceleration_Z.setText(_translate("MainWindow", "Acceleration Z"))
        self.Rotation.setText(_translate("MainWindow", "Rotation:"))
        self.Rotation_X.setText(_translate("MainWindow", "Rotation X:"))
        self.Rotation_Y.setText(_translate("MainWindow", "Rotation Y:"))
        self.Rotation_Z.setText(_translate("MainWindow", "Rotation Z:"))
        self.busvoltage.setText(_translate("MainWindow", "busvoltage"))
        self.power_mW.setText(_translate("MainWindow", "power_mW"))
        self.current_mA.setText(_translate("MainWindow", "current_mA"))


    def update(self):
            print("get data")
            while True:
                HOST = '127.0.0.1'  # The server's hostname or IP address
                PORT = 8888        # The port used by the server

                with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
                    s.connect((HOST, PORT))
                    s.sendall(b't')
                    temp = s.recv(1024)
                    s.close()
                self.temp.setText("Temp: {} C".format(temp))
                print('Received', repr(temp))


                with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
                    s.connect((HOST, PORT))
                    s.sendall(b'h')
                    humi = s.recv(1024)
                    s.close()
                self.humi.setText("Humidity: {} %".format(humi))
                print('Received', repr(humi))


                with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
                    s.connect((HOST, PORT))
                    s.sendall(b'p')
                    precc = s.recv(1024)
                    s.close()
                self.prec.setText("Precc: {} hPa".format(precc))
                print('Received', repr(precc))
                

                
                

    def conne(self):
            
            up = Thread(target=self.update)
            up.start()
            print("conne")
        
            
    def x_r(self):
            requests.get("http://192.168.31.10/on_led")
    def x_l(self):
            requests.get("http://192.168.31.10/off_led")
def contorl():
    pass
    
   
if __name__ == "__main__":
    contorl = Thread(target=contorl)
    contorl.start()
    app = QtWidgets.QApplication(sys.argv)
    window = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(window)
    window.show()
    sys.exit(app.exec_())
