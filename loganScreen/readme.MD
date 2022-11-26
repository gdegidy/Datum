<H1>LoganScreen</H1>
<p>&nbsp;&nbsp;&nbsp;&nbsp;This project uses a display from a broken laptop and a raspberry pi running raspbian to display a dashboard using the service dakboard,
  which is commonly used for "magic mirror" displays.</p>
  <H3>The screen</H3>
  <p>&nbsp;&nbsp;&nbsp;&nbsp;I was lucky enough to find an old broken laptop in the deepest corners of my basement cabinets. I ripped it apart limb by limb saving only the lcd screen and
  hard drive. Since I'm not in computer science, I'm not concerned about destroying all the other parts because I don't know what they are. I looked on the back of the
  display to find a serial number which I searched on google to find a controller board for it on ebay. This board takes power and an HDMI signal and converts it to the 
  gibberish display wiring that I can't understand. I have a raspberry pi below the screen which supplies the HDMI signal to the controller board. <br>
   &nbsp;&nbsp;&nbsp;&nbsp;Since the screen came off of an old laptop, the image got inverted unless it was looked at from a certain angle. I taped tracing paper over the display to fix this.
   The light from the display lights up the tracing paper since it is so thin and close to the display, then you're viewing the lit up paper, rather than the light itself.</p>
  
  <H3>The dashboard</H3>
  <p>&nbsp;&nbsp;&nbsp;&nbsp;The raspberry pi is displaying dakboard, an online service that creates custom dashboard as a website. This website has an interface which allows you to drag elements 
  into place, then a link is generated to view the dashboard. The dashboard was set up on a computer and the raspberry pi is running a browser which goes to the link. I have
  the time and date centered on the top and weather and a calendar on the bottom. Dakboard has a function to display a scrolling headline from an api. I found an api that can
  search for the terms "found dead" and "killed in" in headlines and set that up to display a scrolling headline above the calendar. </p>
  
  <p>Oh yeah also the background is a slide show of my friend Logan. This is linked to dropbox on dakboard which allows people to upload more pictures of Logan.
      I don't have any sort of algorithm to delete non-Logan pictures but I'll say I do.</p>
