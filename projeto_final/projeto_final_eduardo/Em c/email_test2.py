import smtplib
from datetime import datetime as dt

from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.image import MIMEImage

from os import listdir

class send_mail(object):


    #def send(self, file_location):
        file_location = "/home/pi/projeto_final_eduardo/python/fotos/"
	 email_to = "projetoembarcados@gmail.com"
	''
        email_from = "eduardoons@gmail.com"

	# gmail smtp stuff
        smtp_server = 'smtp.gmail.com'
        smtp_port = 587
        smtp_user = email_from

	‘’’ enter your gmail password here - warning this is visible
	    to anyone who can open this file!!’’’
        
        smtp_pass = "projeto1"

	# create message
        msg = MIMEMultipart('alternative')
        msg['To'] = email_to
        msg['From'] = email_from
        

        # get list of attachments i.e. all photos within subdirectory
	‘’’ I used a directory to store photos in and made it so that 
	photos taken within 10 seconds of each other were grouped into the
        same subdirectory
		’’’
        attachment_list = self.get_attachment_list(file_location)
        if len(attachment_list) &gt; 0:
            count = 0
	    # here I make sure the max number of attached photos is 3
            while count &lt; len(attachment_list) and count &lt; 3:
                pic = attachment_list[count]
                file_name = file_location + "image0.jpg"
                image_data = open(file_name, 'rb').read()
                image = MIMEImage(image_data, name=pic)
                msg.attach(image)
                count += 1

        time_now = dt.now().strftime('%H:%M:%S')
        
	# create email subject
        msg['Subject'] = 'Cat Detector: cat detected (%s)' % time_now
	
	# email body
        body = '''Hi Tim,\nA cat has just been detected, see attched picture(s).
                \nBest,\nCatDetector
                '''

        body = MIMEText(body, 'plain')

        # attach body
        msg.attach(body)

	# try and send email
        try:   
            s = smtplib.SMTP(smtp_server, smtp_port)
            s.ehlo()
            s.starttls()
            s.login(smtp_user, smtp_pass)
            s.sendmail(email_from, email_to, msg.as_string())
            print 'email sent'
        except:
            print 'error sending mail'

    def get_attachment_list(self, file_location):
       # use listdir to return all files in directory
       return listdir(file_location)
