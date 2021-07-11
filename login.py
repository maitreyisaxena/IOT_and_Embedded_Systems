from flask import Flask, request,url_for
from flask.templating import render_template
app=Flask(__name__) 

@app.route('/')
def login():
    return render_template('login1.html')

@app.route('/welcome', methods=['GET', 'POST'])
def welcome():
    user='lol'
    password='lmao'
    if request.method=='GET':
        d=request.args
        if d.get('name') and d.get('password'):
            if user==d.get('name') and d.get('password'):
                return render_template('welcome1.html', data=d)
            else:
                return 'invalid credentials'
            
        else:
            return 'provide details'

        

if __name__=="__main__":
    app.run(debug=True)