from  flask import Flask, render_template

app=Flask(__name__)

@app.route('/<float:num1>')

def index(num1):
    return str(num1**2)
    #return render_template('about.html')


if __name__=="__main__":
    app.run(debug=True)
