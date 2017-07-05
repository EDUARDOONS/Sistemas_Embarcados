#Carrega as bibliotecas do email
import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email.mime.image import MIMEImage
from email import encoders

# Carrega as bibliotecas da GPIO e camera
import RPi.GPIO as GPIO
import time
from picamera import PiCamera

# Carrega as bibliotecas
import Adafruit_DHT
import RPi.GPIO as GPIO
import time
 
# Define o tipo de sensor
sensor = Adafruit_DHT.DHT11
#sensor = Adafruit_DHT.DHT22
GPIO.setmode(GPIO.BOARD)
 
# Define a GPIO conectada ao pino de dados do sensor
pino_sensor = 4

#Define a GPIO do sensor PIR
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(11, GPIO.IN)

#Prepara a camera
camera = PiCamera()

#Definicao do email



i=0

while True:
    i+=1
    state = GPIO.input(11) //rece o valor da porta 11 da gpio
    
    if state==0:
        //time.sleep(0.1)
        
    elif state==1:
        #Captura a foto
        print "Movimento detectado"
        camera.capture('/home/pi/projeto_final_eduardo/python/fotos/image%s.jpg' % i)
        camera.stop_preview()

        # Efetua a leitura do sensor
       umid, temp = Adafruit_DHT.read_retry(sensor, pino_sensor);

       # Caso leitura esteja ok, mostra os valores na tela
       if umid is not None and temp is not None:
             print ("Temperatura = {0:0.1f}  Umidade = {1:0.1f}\n").format(temp, umid);
             print ("Aguarda 5 segundos para efetuar nova leitura...\n");
             time.sleep(5)
       else:
             # Mensagem de erro de comunicacao com o sensor
             print("Falha ao ler dados do DHT11 !!!")

        #Envia o email

        fromaddr = "projetoembarcados@gmail.com"
        toaddr = "eduardoons@gmail.com"
 
        msg = MIMEMultipart()
 
        msg['From'] = fromaddr
        msg['To'] = toaddr
        msg['Subject'] = "Movimento detectado - Registro"
 
        body = "Urgente - Verificar camera"
 
        msg.attach(MIMEText(body, 'plain'))
 
        filename = "image0.pjg"
        attachment = open("/home/pi/projeto_final_eduardo/python/fotos/image0.jpg", "rb")
 
        part = MIMEBase('application', 'octet-stream')
        part.set_payload((attachment).read())
        encoders.encode_base64(part)
        part.add_header('Content-Disposition', "attachment; filename= %s" % filename)

        msg.attach(part)

        filename = "image1.pjg"
        attachment = open("/home/pi/projeto_final_eduardo/python/fotos/image1.jpg", "rb")
 
        part = MIMEBase('application', 'octet-stream')
        part.set_payload((attachment).read())
        encoders.encode_base64(part)
        part.add_header('Content-Disposition', "attachment; filename= %s" % filename)

        msg.attach(part)

        server = smtplib.SMTP('smtp.gmail.com', 587)
        server.starttls()
        server.login(fromaddr, "projeto1")
        text = msg.as_string()
        server.sendmail(fromaddr, toaddr, text)
        server.quit()

 
        

