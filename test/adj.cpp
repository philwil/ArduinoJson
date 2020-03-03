
#include <iostream>
#include <sstream>
#include <ArduinoJson.h>
//sudo cp -a  ../src/ArduinoJson* /usr/local/include
using namespace std;


char json[] =
      "{\"sensor\":\"gps\",\"time\":1351824120,\"data\":[48.756080,2.302038]}";


int main ( int argc, char * argv[])
{
  StaticJsonDocument<1024> doc;
  // Deserialize the JSON document
  // Add values in the document
  //
  stringstream ss;
  
  doc["sensor"] = "gps";
  doc["time"] = 135182;

  // Add an array.
  //

  doc["motors"] = doc.createNestedObject("motors");
  doc["motors"]["power"] = 150;
  doc["motors"]["state"] = "on";
  doc["motors"]["val"] = "value";
  //JsonArray data = doc.createNestedArray("data");
  doc["data"] = doc.createNestedArray("data");
  //data.add(48.756080);
  //data.add(2.302038);
  doc["data"].add(48.756080);
  doc["data"].add(2.345);
		//doc.createNestedObject("motors");
  bool ok1 = doc.containsKey( "fun" );
  bool ok2 = doc.containsKey( "data" );
  int dsize = doc.size();
  int dasize = doc["data"].size();
  cout << " ok1 (fun) " << ok1 << endl;
  cout << " ok2 (data) " << ok2 << endl;
  cout << " dsize: " << dsize << endl;
  cout << " dasize: " << dasize << endl;
  int i;
  for (i = 0; i < dsize; i++) {
    JsonObject d = doc.getElement(i);
    cout <<" indx :" << i << endl;
    //cout <<" key :" << d.as<char *>() << endl;
  }
  
  //for (JsonObject::iterator it = doc.begin(); it != doc.end(); ++ it){
  //ss = it->key;
  //cout << "Key : "<<ss.str() << " " ;
    //cout << "val : "<<((it->value).as<char *>()) ;
  //}
  
  //JsonObject motors = doc.createNestedObject("motors");
  //JsonObject power = motors.createNestedObject("power");
  //JsonObject state = power.createNestedObject("state");
  //JsonObject level = power.createNestedObject("level");

  //data.add(power);
  //state.value = 150;
  //power["level"] = 150;
  //power["state"] = "on";

  // Generate the minified JSON and send it to a string.
  //
  long time1 = doc["time"];

  size_t err =  serializeJson(doc, ss);
  
  cout << "serial error  " << err<<endl;
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
