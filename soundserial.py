from mutagen.mp3 import MP3 as mp3
import pygame
import serial
import time
ser=serial.Serial('/dev/ttyACM0', 9600, timeout=0.1)
while True:
	c=ser.read()
	val=int.from_bytes(c, 'big')
	print(val)
	filename='Little-dog-barking-sound.mp3' #再生したいmp3ファイル
	pygame.mixer.init()
	pygame.mixer.music.load(filename) #音源を読み込み
	mp3_length = mp3(filename).info.length #音源の長さ取得
	pygame.mixer.music.play(5) #再生開始。1の部分を変えるとn回再生(その場合は次の行の秒数も×nすること)
	time.sleep(mp3_length + 0.25) #再生開始後、音源の長さだけ待つ(0.25待つのは誤差解消)
	pygame.mixer.music.stop() #音源の長さ待ったら再生停止
	val = 3
	valByte = val.to_bytes(1, 'big')
	# valByte = val.to_bytes(2, 'little')
	ser.write(valByte)
	print(val)
	time.sleep(1)
