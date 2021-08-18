import requests
from datetime import date

def getTimeFromStr(t) :
    time = t[:-3]
    curr = t[-2:]
    times = time.split(':')
    hours = int(times[0])
    minutes = int(times[1])
    sec = int(times[2])

    if curr == "AM" : 
        hours%=12
    else : 
        if hours!=12:
            hours+=12

    curr_time_in_sec = hours*60*60 + minutes*60 + sec

    curr_local_time = curr_time_in_sec + 19800

    return curr_local_time

def getTimeFromFloat(s) : 
    hours = int(s // 3600)
    s%=3600
    minutes = int(s // 60)
    s%=60
    s=int(s)

    t = str(hours) + ":" + str(minutes) + ":" + str(s)

    return t

get_location_url = "https://api.sunrise-sunset.org/json"

latitude = 30.9331
longitude = 74.6225

PARAMS = {'lat':latitude, 'lng':longitude}

r = requests.get(url = get_location_url, params = PARAMS)

data = r.json()

sunrise_time = getTimeFromStr(data['results']['sunrise'])
sunset_time = getTimeFromStr(data['results']['sunset'])
time_between = sunset_time - sunrise_time

pahar_time = time_between/8

switcherR = {
    0 : 2,
    1 : 7,
    2 : 5,
    3 : 6,
    4 : 4,
    5 : 3,
    6 : 8,
}

switcherY = {
    0 : 4,
    1 : 3,
    2 : 2,
    3 : 1,
    4 : 7,
    5 : 6,
    6 : 5,
}

switcherG = {
    0 : 6,
    1 : 5,
    2 : 4,
    3 : 3,
    4 : 2,
    5 : 1,
    6 : 7,
}

rahukalamStart = sunrise_time + (pahar_time * (switcherR[date.today().weekday()] - 1))
rahukalamEnd = rahukalamStart + pahar_time

yamagandamStart = sunrise_time + (pahar_time * (switcherY[date.today().weekday()] - 1))
yamagandamEnd = yamagandamStart + pahar_time

gulikaStart = sunrise_time + (pahar_time * (switcherG[date.today().weekday()] - 1))
gulikaEnd = gulikaStart + pahar_time

output = """RahuKalam starts at {rahuS}\nRahuKalam ends at {rahuE}\n\nYamagandam starts at {yamS}
Yamagandam ends at {yamE}\n\nGulika starts at {gulS}\nGulika ends at {gulE}"""

print(output.format(rahuS=getTimeFromFloat(rahukalamStart), rahuE=getTimeFromFloat(rahukalamEnd), 
yamS=getTimeFromFloat(yamagandamStart), yamE=getTimeFromFloat(yamagandamEnd), 
gulS=getTimeFromFloat(gulikaStart), gulE=getTimeFromFloat(gulikaEnd)))


# {'results': {'sunrise': '12:13:37 AM', 'sunset': '2:02:27 PM', 
# 'solar_noon': '7:08:02 AM', 'day_length': '13:48:50', 'civil_twilight_begin': '11:46:56 PM', 
# 'civil_twilight_end': '2:29:08 PM', 'nautical_twilight_begin': '11:14:40 PM', 
# 'nautical_twilight_end': '3:01:24 PM', 'astronomical_twilight_begin': '10:40:32 PM', 
# 'astronomical_twilight_end': '3:35:32 PM'}, 'status': 'OK'}
