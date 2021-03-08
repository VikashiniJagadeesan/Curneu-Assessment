#include <string>
#include <iostream>
#include <fstream>
#include "json.h"

using namespace std;

int main()
{
  //Json::CharReaderBuilder reader;
  Json::Value root;
  Json::CharReaderBuilder builder;
  Json::CharReader * reader = builder.newCharReader();
	string errors;
  string json [] ="( 
  {
    	{ "balaji.sivakumar@curneu.com": { "userBasicDetails": { "userId": "IND0001", 
        "Email": "balaji@curneu.com", 
        "Country": "India", 
        "HospitalName": "CMC", 
        "Password": "K@123", 
		"UserGender": "Male",
        "UserName": "BalajiSivakumar" } 
		}
		 }
    }
    )";
  bool parsingSuccessful = reader->parse(json.c_str(), json.c_str() + json.size(), &root, &errors);
  delete reader;

  if ( !parsingSuccessful )
  {
    cout << json << endl;
    cout << errors << endl;
  }
  bool parseSuccess = true;//reader.parse(json, root, false);
	
  if (parseSuccess)
  {
    const Json::Value resultValue = root["result"];
    cout << "Result is " << resultValue.asString() << "\n";
  }

  /*Json::StyledWriter styledWriter;
  Json::FastWriter fastWriter;
  Json::Value newValue;
  newValue["result"] = "ok";

  cout << styledWriter.write(newValue) << "\n";
  cout << fastWriter.write(newValue) << "\n";
*/
  return 0;
}
