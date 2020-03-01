
#include <iostream>
#include <sstream>
#include <foo.h>
#include <ArduinoJson.h>

using namespace std;


char json[] =
      "{\"sensor\":\"gps\",\"time\":1351824120,\"data\":[48.756080,2.302038]}";


int main ( int argc, char * argv[])
{
  StaticJsonDocument<200> doc;
  // Deserialize the JSON document
  // Add values in the document
  //
  stringstream ss;
  
  doc["sensor"] = "gps";
  doc["time"] = 135182;

  // Add an array.
  //
  JsonArray data = doc.createNestedArray("data");
  JsonObject motors = doc.createNestedObject("motors");
  JsonObject power = motors.createNestedObject("power");
  data.add(48.756080);
  data.add(2.302038);
  power["level"] = 150;
  power["state"] = "on";

  // Generate the minified JSON and send it to a string.
  //
  long time1 = doc["time"];

  serializeJson(doc, ss);
  
  cout << "ss out " << ss.str()<<endl;
  cout << " hello time 1 " << time1<< endl;
  
  DeserializationError error = deserializeJson(doc, json);
  const char* sensor = doc["sensor"];
  long time2 = doc["time"];
  double latitude = doc["data"][0];
  double longitude = doc["data"][1];
  
  cout << " hello time2 " << time2<< endl;
  return 0;
}
