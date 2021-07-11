from flask import Flask,request, render_template,flash,redirect,url_for
from flask_sqlalchemy import SQLAlchemy
app=Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI']='sqlite:///test.db'
db=SQLAlchemy(app)
app.secret_key='4141mncx'
class User(db.Model): 
    id=db.Column(db.Integer, primary_key=True)
    username=db.Column(db.String(20), unique=True, nullable=False)
    email=db.Column(db.String(130), unique=True, nullable=False)
    name=db.Column(db.String(50), nullable=False)
    password=db.Column(db.String(7))

    def __repr__(self):
        return '<User {0}>'.format(self.username)

@app.route('/', methods=['GET', 'POST'])
def login():
    return render_template('login1.html')

@app.route('/register',methods=['GET','POST'])
def register():
    if request.method=="POST":
        data=request.form 
        print(data)
        conditions=[value !='' for key,value in data.items()]
        conditions.append(data.get('password')==data.get('confirm_password'))
        print(conditions)
        if all(conditions):
            print('all conditions are satisfied')
        else:
            print('something is missing')
        user=User(
            name=data.get('name'),
            username=data.get('username'),
            email=data.get('email'),
            password=data.get('password')

        )
        db.session.add(user)
        db.session.commit()
    return render_template('register.html')

@app.route('/welcome', methods=['GET','POST'])
def welcome():
    if request.method=='POST':

        username=request.form.get('username')
        password=request.form.get('password')
        #print(username)
        #print( password)

        users=User.query.all()
        #print(users)
        user_found=False
        for user in users:
            
            if user.username==username:
                print('found')
                user_found=True
                if user.password==password:
                    print('match')
                    return render_template('welcome1.html', user=username)
                else:
                    flash('invalid credentials')
                    return redirect(url_for('login'))
                
        if user_found:
            flash('user no registered')
            return redirect(url_for('login'))
    flash('make sure to login')
    return redirect(url_for('login'))    

        
@app.route('/users')
def reg_users():
    return render_template('reg_users.html', users=User.query.all())
    

    
if __name__=="__main__":
    app.run(debug=True)



