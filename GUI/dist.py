from flask import Flask
from flask_limiter import Limiter
from flask_limiter.util import get_remote_address
import serial
ser = serial.Serial('COM4')


app = Flask(__name__)
limiter = Limiter(
    app,
    key_func=get_remote_address,
    default_limits=["200 per day", "50 per hour"]
)
@app.route("/dist")
@limiter.exempt
def hello_world():
	kek = ser.readline()
	return kek
	

app.run()