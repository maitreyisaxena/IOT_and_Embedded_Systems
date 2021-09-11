
from flask import Flask, render_template, request, jsonify

app = Flask(__name__)

led_state = 0
brightness = 50

class LED():
    def __init__(self, state):
        self.state = state
    def __repr__(self):
        if self.state == 0:
            return "OFF"
        else:
            return "ON"

led = LED(0)

@app.route('/led', methods=['GET', 'POST'])
def ledControl():
    global led
    try:
        if request.method == 'POST':
            if request.form.get('led') == "on":
                print("LEDON")
                led.state = 1
            elif request.form.get('led') == 'off':
                led.state = 0
    except:
        pass
    finally:
        return render_template('led_control.html', led=led)

@app.route('/state')
def ledState():
    global led
    return jsonify({'led':led.state})

if __name__ == "__main__":
    app.run(debug=True)
