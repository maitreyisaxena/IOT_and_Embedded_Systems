import serial, requests
com=serial.Serial('COM1',9600)
while True:
    res=requests.get('enter the url of  your website').json().get('led')
    print (res)
    com.write(str(res).encode())
