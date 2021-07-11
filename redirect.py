from flask import Flask, redirect, url_for

app=Flask(__name__)

@app.route('/<pagename>')
def index(pagename):
    if pagename=='home':
        return redirect(url_for(home))
    elif pagename=='about':
        return redirect(url_for(about))
    elif pagename=='login':
        return redirect(url_for(login))
    else:
        return "this is main page"
    

@app.route('/home')
def home():
    return 'this is home page'

@app.route('/about')
def about():
    return 'this is about page'

@app.route('/login')
def login():
    return 'this is login page'

if __name__ == '__main__':
    app.run(debug=True)
