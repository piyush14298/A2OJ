import shodan

# Setup the API wrapper
api = shodan.Shodan('rXHpIS6YdCR5lY52iCKHOBU1coytX7P9') # Free API key from https://account.shodan.io

# Lookup the list of services an IP runs
VISITOR_IP='117.234.111.128'
try:
    ipinfo = api.host(VISITOR_IP)
except:
    print('This is a normal IP')
    exit(0)


# Check whether the IP runs a VPN service by looking for the "vpn" tag
if 'tags' in ipinfo and 'vpn' in ipinfo['tags']:
    print('{} is connecting from a VPN'.format(VISITOR_IP))

elif 'tags' in ipinfo and 'cloud' in ipinfo['tags']:
    print('{} is connecting from a cloud'.format(VISITOR_IP))
