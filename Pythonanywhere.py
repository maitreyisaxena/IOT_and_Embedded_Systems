import serial, requests
com=serial.Serial('COM1',9600)
while True:
    res=requests.get('https://maitreyi01.pythonanywhere.com/state').json().get('led')
    print (res)
    com.write(str(res).encode())
