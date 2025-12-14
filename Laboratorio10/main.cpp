#include <cstdlib>
#include <iostream>
#include <fstream> 
#include "network.h"
#include "list-array.h"

using namespace network;
using namespace list;
using namespace std;

int main(){
  cout<<boolalpha;
  Network net=createEmptyNetwork();
  unsigned i=1;
  unsigned ret=0;
  bool bres=false;
  bool breq=false;
  string sreq="";
  string sres="";
  List lres;

  cout<<"*************** Test "<<i<<": net=createEmptyNetwork();isEmpty(net)  ****************"<<endl;
  bres=isEmpty(net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  addMember(\"GroszBarbara\",net)  ****************"<<endl;
  bres=addMember("GroszBarbara",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": isEmpty(net)  ****************"<<endl;
  bres=isEmpty(net);
  breq=false;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  addMember(\"GroszBarbara\",net)  ****************"<<endl;
  bres=addMember("GroszBarbara",net);
  breq=false;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  addMember(\"LovelaceAda\",net)  ****************"<<endl;
  bres=addMember("LovelaceAda",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  addMember(\"LovelaceAda\",net)  ****************"<<endl;
  bres=addMember("LovelaceAda",net);
  breq=false;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  addMember(\"HopperGrace\",net)  ****************"<<endl;
  bres=addMember("HopperGrace",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

 

  cout<<"*************** Test "<<i<<":  addMember(\"BorgAnita\",net)  ****************"<<endl;
  bres=addMember("BorgAnita",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  areFriends(\"LovelaceAda\",\"BorgAnita\",net)  ****************"<<endl;
  bres=areFriends("LovelaceAda","BorgAnita",net);
  breq=false;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;
  
  cout<<"*************** Test "<<i<<":  becomeFriends(\"BorgAnita\",\"LovelaceAda\",net)  ****************"<<endl;
  bres=becomeFriends("BorgAnita","LovelaceAda",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;
   

  cout<<"*************** Test "<<i<<":  areFriends(\"BorgAnita\",\"LovelaceAda\",net)  ****************"<<endl;
  bres=areFriends("BorgAnita","LovelaceAda",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  areFriends(\"LovelaceAda\",\"BorgAnita\",net)  ****************"<<endl;
  bres=areFriends("LovelaceAda","BorgAnita",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  addMember(\"JohnsonKatherine\",net)  ****************"<<endl;
  bres=addMember("JohnsonKatherine",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  becomeFriends(\"LovelaceAda\",\"JohnsonKatherine\",net)  ****************"<<endl;
  bres=becomeFriends("LovelaceAda","JohnsonKatherine",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  areFriends(\"LovelaceAda\",\"JohnsonKatherine\",net)  ****************"<<endl;
  bres=areFriends("LovelaceAda","JohnsonKatherine",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  areFriends(\"LovelaceAda\",\"TuringAlan\",net)  ****************"<<endl;
  bres=areFriends("LovelaceAda","TuringAlan",net);
  breq=false;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  areFriends(\"ChurchAlonso\",\"TuringAlan\",net)  ****************"<<endl;
  bres=areFriends("ChurchAlonso","TuringAlan",net);
  breq=false;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  becomeFriends(\"HopperGrace\",\"GroszBarbara\",net)  ****************"<<endl;
  bres=becomeFriends("HopperGrace","GroszBarbara",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  areFriends(\"HopperGrace\",\"GroszBarbara\",net)  ****************"<<endl;
  bres=areFriends("HopperGrace","GroszBarbara",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  areFriends(\"GroszBarbara\",\"HopperGrace\",net)  ****************"<<endl;
  bres=areFriends("GroszBarbara","HopperGrace",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  addMember(\"GoldbergAdele\",net)  ****************"<<endl;
  bres=addMember("GoldbergAdele",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  becomeFriends(\"LovelaceAda\",\"GoldbergAdele\",net)  ****************"<<endl;
  bres=becomeFriends("LovelaceAda","GoldbergAdele",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  areFriends(\"GoldbergAdele\",\"LovelaceAda\",net)  ****************"<<endl;
  bres=areFriends("GoldbergAdele","LovelaceAda",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  addMember(\"AngluinDana\",net)  ****************"<<endl;
  bres=addMember("AngluinDana",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  areFriends(\"AngluinDana\",\"LovelaceAda\",net)  ****************"<<endl;
  bres=areFriends("AngluinDana","LovelaceAda",net);
  breq=false;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  becomeFriends(\"AngluinDana\",\"LovelaceAda\",net)  ****************"<<endl;
  bres=becomeFriends("AngluinDana","LovelaceAda",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  areFriends(\"AngluinDana\",\"LovelaceAda\",net)  ****************"<<endl;
  bres=areFriends("AngluinDana","LovelaceAda",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  becomeFriends(\"AngluinDana\",\"GroszBarbara\",net)  ****************"<<endl;
  bres=becomeFriends("AngluinDana","GroszBarbara",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  areFriends(\"GroszBarbara\",\"AngluinDana\",net)  ****************"<<endl;
  bres=areFriends("GroszBarbara","AngluinDana",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  addMember(\"ConwayLynn\",net)  ****************"<<endl;
  bres=addMember("ConwayLynn",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  addMember(\"ConwayLynn\",net)  ****************"<<endl;
  bres=addMember("ConwayLynn",net);
  breq=false;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  becomeFriends(\"ConwayLynn\",\"GroszBarbara\",net)  ****************"<<endl;
  bres=becomeFriends("ConwayLynn","GroszBarbara",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  becomeFriends(\"ConwayLynn\",\"GroszBarbara\",net)  ****************"<<endl;
  bres=becomeFriends("ConwayLynn","GroszBarbara",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  areFriends(\"GroszBarbara\",\"ConwayLynn\",net)  ****************"<<endl;
  bres=areFriends("GroszBarbara","ConwayLynn",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  addMember(\"ShawCarol\",net)  ****************"<<endl;
  bres=addMember("ShawCarol",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  createGroup(\"ShawCarol\",\"Soccer\",net)  ****************"<<endl;
  bres=createGroup("ShawCarol","Soccer",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  createGroup(\"AngluinDana\",\"Soccer\",net)  ****************"<<endl;
  bres=createGroup("AngluinDana","Soccer",net);
  breq=false;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  createGroup(\"LovelaceAda\",\"Hiking\",net)  ****************"<<endl;
  bres=createGroup("LovelaceAda","Hiking",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  addMember(\"HamiltonMargaret\",net)  ****************"<<endl;
  bres=addMember("HamiltonMargaret",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  becomeFriends(\"LovelaceAda\",\"HamiltonMargaret\",net)  ****************"<<endl;
  bres=becomeFriends("LovelaceAda","HamiltonMargaret",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  becomeFriends(\"HamiltonMargaret\",\"GoldbergAdele\",net)  ****************"<<endl;
  bres=becomeFriends("HamiltonMargaret","GoldbergAdele",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  createGroup(\"HamiltonMargaret\",\"Hiking\",net)  ****************"<<endl;
  bres=createGroup("HamiltonMargaret","Hiking",net);
  breq=false;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  createGroup(\"HamiltonMargaret\",\"Climbing\",net)  ****************"<<endl;
  bres=createGroup("HamiltonMargaret","Climbing",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  joinGroup(\"AngluinDana\",\"Soccer\",net)  ****************"<<endl;
  bres=joinGroup("AngluinDana","Soccer",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  joinGroup(\"AngluinDana\",\"Running\",net)  ****************"<<endl;
  bres=joinGroup("AngluinDana","Running",net);
  breq=false;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  joinGroup(\"TuringAlan\",\"Soccer\",net)  ****************"<<endl;
  bres=joinGroup("TuringAlan","Soccer",net);
  breq=false;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  createGroup(\"LovelaceAda\",\"Chess\",net)  ****************"<<endl;
  bres=createGroup("LovelaceAda","Chess",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  addMember(\"EasleyAnnie\",net)  ****************"<<endl;
  bres=addMember("EasleyAnnie",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  becomeFriends(\"EasleyAnnie\",\"ShawCarol\",net)  ****************"<<endl;
  bres=becomeFriends("EasleyAnnie","ShawCarol",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  areFriends(\"EasleyAnnie\",\"ShawCarol\",net)  ****************"<<endl;
  bres=areFriends("EasleyAnnie","ShawCarol",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  areFriends(\"ShawCarol\",\"EasleyAnnie\",net)  ****************"<<endl;
  bres=areFriends("ShawCarol","EasleyAnnie",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  leaveFriendship(\"ShawCarol\",\"EasleyAnnie\",net)  ****************"<<endl;
  bres=leaveFriendship("ShawCarol","EasleyAnnie",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  areFriends(\"EasleyAnnie\",\"ShawCarol\",net)  ****************"<<endl;
  bres=areFriends("EasleyAnnie","ShawCarol",net);
  breq=false;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  areFriends(\"ShawCarol\",\"EasleyAnnie\",net)  ****************"<<endl;
  bres=areFriends("ShawCarol","EasleyAnnie",net);
  breq=false;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  addMember(\"EasleyAnnie\",net)  ****************"<<endl;
  bres=addMember("EasleyAnnie",net);
  breq=false;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  leaveFriendship(\"JohnsonKatherine\",\"TuringAlan\",net)  ****************"<<endl;
  bres=leaveFriendship("JohnsonKatherine","TuringAlan",net);
  breq=false;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  leaveFriendship(\"JohnsonKatherine\",\"LovelaceAda\",net)  ****************"<<endl;
  bres=leaveFriendship("JohnsonKatherine","LovelaceAda",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": areFriends(\"JohnsonKatherine\",\"LovelaceAda\",net)  ****************"<<endl;
  bres=areFriends("JohnsonKatherine","LovelaceAda",net);
  breq=false;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": areFriends(\"LovelaceAda\",\"JohnsonKatherine\",net)  ****************"<<endl;
  bres=areFriends("LovelaceAda","JohnsonKatherine",net);
  breq=false;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  createGroup(\"LovelaceAda\",\"Cycling\",net)  ****************"<<endl;
  bres=createGroup("LovelaceAda","Cycling",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;
  
  cout<<"*************** Test "<<i<<":  createGroup(\"EasleyAnnie\",\"Swimming\",net)  ****************"<<endl;
  bres=createGroup("EasleyAnnie","Swimming",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": areFriends(\"LovelaceAda\",\"JohnsonKatherine\",net)  ****************"<<endl;
  bres=areFriends("LovelaceAda","JohnsonKatherine",net);
  breq=false;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": members(net)  ****************"<<endl;
  lres=members(net);
  sres=toString(lres);
  clear(lres);
  sreq="AngluinDana; BorgAnita; ConwayLynn; EasleyAnnie; GoldbergAdele; GroszBarbara; HamiltonMargaret; HopperGrace; JohnsonKatherine; LovelaceAda; ShawCarol;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": groups(net)  ****************"<<endl;
  lres=groups(net);
  sres=toString(lres);
  clear(lres);
  sreq="Chess; Climbing; Cycling; Hiking; Soccer; Swimming;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": friends(\"AngluinDana\",net)  ****************"<<endl;
  lres=friends("AngluinDana",net);
  sres=toString(lres);
  clear(lres);
  sreq="GroszBarbara; LovelaceAda;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": memberOf(\"AngluinDana\",net)  ****************"<<endl;
  lres=memberOf("AngluinDana",net);
  sres=toString(lres);
  clear(lres);
  sreq="Chess; Cycling; Hiking; Soccer;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": creatorOf(\"AngluinDana\",net)  ****************"<<endl;
  lres=creatorOf("AngluinDana",net);
  sres=toString(lres);
  clear(lres);
  sreq="";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": friends(\"TuringAlan\",net)  ****************"<<endl;
  lres=friends("TuringAlan",net);
  sres=toString(lres);
  clear(lres);
  sreq="";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": memberOf(\"TuringAlan\",net)  ****************"<<endl;
  lres=memberOf("TuringAlan",net);
  sres=toString(lres);
  clear(lres);
  sreq="";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": creatorOf(\"TuringAlan\",net)  ****************"<<endl;
  lres=creatorOf("TuringAlan",net);
  sres=toString(lres);
  clear(lres);
  sreq="";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": friends(\"BorgAnita\",net)  ****************"<<endl;
  lres=friends("BorgAnita",net);
  sres=toString(lres);
  clear(lres);
  sreq="LovelaceAda;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": memberOf(\"BorgAnita\",net)  ****************"<<endl;
  lres=memberOf("BorgAnita",net);
  sres=toString(lres);
  clear(lres);
  sreq="Chess; Cycling; Hiking;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": creatorOf(\"BorgAnita\",net)  ****************"<<endl;
  lres=creatorOf("BorgAnita",net);
  sres=toString(lres);
  clear(lres);
  sreq="";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": friends(\"ConwayLynn\",net)  ****************"<<endl;
  lres=friends("ConwayLynn",net);
  sres=toString(lres);
  clear(lres);
  sreq="GroszBarbara;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": memberOf(\"ConwayLynn\",net)  ****************"<<endl;
  lres=memberOf("ConwayLynn",net);
  sres=toString(lres);
  clear(lres);
  sreq="";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": creatorOf(\"ConwayLynn\",net)  ****************"<<endl;
  lres=creatorOf("ConwayLynn",net);
  sres=toString(lres);
  clear(lres);
  sreq="";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": friends(\"EasleyAnnie\",net)  ****************"<<endl;
  lres=friends("EasleyAnnie",net);
  sres=toString(lres);
  clear(lres);
  sreq="";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": memberOf(\"EasleyAnnie\",net)  ****************"<<endl;
  lres=memberOf("EasleyAnnie",net);
  sres=toString(lres);
  clear(lres);
  sreq="Swimming;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": creatorOf(\"EasleyAnnie\",net)  ****************"<<endl;
  lres=creatorOf("EasleyAnnie",net);
  sres=toString(lres);
  clear(lres);
  sreq="Swimming;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": friends(\"GoldbergAdele\",net)  ****************"<<endl;
  lres=friends("GoldbergAdele",net);
  sres=toString(lres);
  clear(lres);
  sreq="HamiltonMargaret; LovelaceAda;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": memberOf(\"GoldbergAdele\",net)  ****************"<<endl;
  lres=memberOf("GoldbergAdele",net);
  sres=toString(lres);
  clear(lres);
  sreq="Chess; Climbing; Cycling; Hiking;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": creatorOf(\"GoldbergAdele\",net)  ****************"<<endl;
  lres=creatorOf("GoldbergAdele",net);
  sres=toString(lres);
  clear(lres);
  sreq="";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": friends(\"GroszBarbara\",net)  ****************"<<endl;
  lres=friends("GroszBarbara",net);
  sres=toString(lres);
  clear(lres);
  sreq="AngluinDana; ConwayLynn; HopperGrace;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": memberOf(\"GroszBarbara\",net)  ****************"<<endl;
  lres=memberOf("GroszBarbara",net);
  sres=toString(lres);
  clear(lres);
  sreq="";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": creatorOf(\"GroszBarbara\",net)  ****************"<<endl;
  lres=creatorOf("GroszBarbara",net);
  sres=toString(lres);
  clear(lres);
  sreq="";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": friends(\"HamiltonMargaret\",net)  ****************"<<endl;
  lres=friends("HamiltonMargaret",net);
  sres=toString(lres);
  clear(lres);
  sreq="GoldbergAdele; LovelaceAda;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": memberOf(\"HamiltonMargaret\",net)  ****************"<<endl;
  lres=memberOf("HamiltonMargaret",net);
  sres=toString(lres);
  clear(lres);
  sreq="Chess; Climbing; Cycling;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": creatorOf(\"HamiltonMargaret\",net)  ****************"<<endl;
  lres=creatorOf("HamiltonMargaret",net);
  sres=toString(lres);
  clear(lres);
  sreq="Climbing;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": friends(\"HopperGrace\",net)  ****************"<<endl;
  lres=friends("HopperGrace",net);
  sres=toString(lres);
  clear(lres);
  sreq="GroszBarbara;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": memberOf(\"HopperGrace\",net)  ****************"<<endl;
  lres=memberOf("HopperGrace",net);
  sres=toString(lres);
  clear(lres);
  sreq="";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": creatorOf(\"HopperGrace\",net)  ****************"<<endl;
  lres=creatorOf("HopperGrace",net);
  sres=toString(lres);
  clear(lres);
  sreq="";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": friends(\"JohnsonKatherine\",net)  ****************"<<endl;
  lres=friends("JohnsonKatherine",net);
  sres=toString(lres);
  clear(lres);
  sreq="";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": memberOf(\"JohnsonKatherine\",net)  ****************"<<endl;
  lres=memberOf("JohnsonKatherine",net);
  sres=toString(lres);
  clear(lres);
  sreq="Chess; Hiking;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": creatorOf(\"JohnsonKatherine\",net)  ****************"<<endl;
  lres=creatorOf("JohnsonKatherine",net);
  sres=toString(lres);
  clear(lres);
  sreq="";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": friends(\"LovelaceAda\",net)  ****************"<<endl;
  lres=friends("LovelaceAda",net);
  sres=toString(lres);
  clear(lres);
  sreq="AngluinDana; BorgAnita; GoldbergAdele; HamiltonMargaret;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": memberOf(\"LovelaceAda\",net)  ****************"<<endl;
  lres=memberOf("LovelaceAda",net);
  sres=toString(lres);
  clear(lres);
  sreq="Chess; Climbing; Cycling; Hiking;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": creatorOf(\"LovelaceAda\",net)  ****************"<<endl;
  lres=creatorOf("LovelaceAda",net);
  sres=toString(lres);
  clear(lres);
  sreq="Chess; Cycling; Hiking;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": friends(\"ShawCarol\",net)  ****************"<<endl;
  lres=friends("ShawCarol",net);
  sres=toString(lres);
  clear(lres);
  sreq="";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": memberOf(\"ShawCarol\",net)  ****************"<<endl;
  lres=memberOf("ShawCarol",net);
  sres=toString(lres);
  clear(lres);
  sreq="Soccer;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": creatorOf(\"ShawCarol\",net)  ****************"<<endl;
  lres=creatorOf("ShawCarol",net);
  sres=toString(lres);
  clear(lres);
  sreq="Soccer;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": leaveGroup(\"BorgAnita\",\"Chess\",net)  ****************"<<endl;
  bres=leaveGroup("BorgAnita","Chess",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": leaveGroup(\"BorgAnita\",\"Chess\",net)  ****************"<<endl;
  bres=leaveGroup("BorgAnita","Chess",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;
      

  cout<<"*************** Test "<<i<<": memberOf(\"BorgAnita\",net)  ****************"<<endl;
  lres=memberOf("BorgAnita",net);
  sres=toString(lres);
  clear(lres);
  sreq="Cycling; Hiking;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": joinGroup(\"BorgAnita\",\"Chess\",net)  ****************"<<endl;
  bres=joinGroup("BorgAnita","Chess",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": memberOf(\"BorgAnita\",net)  ****************"<<endl;
  lres=memberOf("BorgAnita",net);
  sres=toString(lres);
  clear(lres);
  sreq="Chess; Cycling; Hiking;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": leaveGroup(\"TuringAlan\",\"Chess\",net)  ****************"<<endl;
  bres=leaveGroup("TuringAlan","Chess",net);
  breq=false;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": leaveGroup(\"HamiltonMargaret\",\"Rugby\",net)  ****************"<<endl;
  bres=leaveGroup("HamitlonMargaret","Rugby",net);
  breq=false;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": joinGroup(\"HopperGrace\",\"Soccer\",net)  ****************"<<endl;
  bres=joinGroup("HopperGrace","Soccer",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": memberOf(\"HopperGrace\",net)  ****************"<<endl;
  lres=memberOf("HopperGrace",net);
  sres=toString(lres);
  clear(lres);
  sreq="Soccer;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": leaveGroup(\"ShawCarol\",\"Soccer\",net)  ****************"<<endl;
  bres=leaveGroup("ShawCarol","Soccer",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": groups(net)  ****************"<<endl;
  lres=groups(net);
  sres=toString(lres);
  clear(lres);
  sreq="Chess; Climbing; Cycling; Hiking; Swimming;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": memberOf(\"ShawCarol\",net)  ****************"<<endl;
  lres=memberOf("ShawCarol",net);
  sres=toString(lres);
  clear(lres);
  sreq="";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": craatorOf(\"ShawCarol\",net)  ****************"<<endl;
  lres=creatorOf("ShawCarol",net);
  sres=toString(lres);
  clear(lres);
  sreq="";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": memberOf(\"AngluinDana\",net)  ****************"<<endl;
  lres=memberOf("AngluinDana",net);
  sres=toString(lres);
  clear(lres);
  sreq="Chess; Cycling; Hiking;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  leaveFriendship(\"GoldbergAdele\",\"LovelaceAda\",net)  ****************"<<endl;
  bres=leaveFriendship("GoldbergAdele","LovelaceAda",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": friends(\"GoldbergAdele\",net)  ****************"<<endl;
  lres=friends("GoldbergAdele",net);
  sres=toString(lres);
  clear(lres);
  sreq="HamiltonMargaret;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": friends(\"LovelaceAda\",net)  ****************"<<endl;
  lres=friends("LovelaceAda",net);
  sres=toString(lres);
  clear(lres);
  sreq="AngluinDana; BorgAnita; HamiltonMargaret;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": friends(\"LovelaceAda\",net)  ****************"<<endl;
  lres=friends("LovelaceAda",net);
  sres=toString(lres);
  clear(lres);
  sreq="AngluinDana; BorgAnita; HamiltonMargaret;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  CreateGroup(\"GoldbergAdele\",\"Rugby\",net)  ****************"<<endl;
  bres=createGroup("GoldbergAdele","Rugby",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": groups(net)  ****************"<<endl;
  lres=groups(net);
  sres=toString(lres);
  clear(lres);
  sreq="Chess; Climbing; Cycling; Hiking; Rugby; Swimming;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": creatorOf(\"GoldbergAdele\",net)  ****************"<<endl;
  lres=creatorOf("GoldbergAdele",net);
  sres=toString(lres);
  clear(lres);
  sreq="Rugby;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": memberOf(\"GoldbergAdele\",net)  ****************"<<endl;
  lres=memberOf("GoldbergAdele",net);
  sres=toString(lres);
  clear(lres);
  sreq="Chess; Climbing; Cycling; Hiking; Rugby;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": memberOf(\"HamiltonMargaret\",net)  ****************"<<endl;
  lres=memberOf("HamiltonMargaret",net);
  sres=toString(lres);
  clear(lres);
  sreq="Chess; Climbing; Cycling; Rugby;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": memberOf(\"LovelaceAda\",net)  ****************"<<endl;
  lres=memberOf("LovelaceAda",net);
  sres=toString(lres);
  clear(lres);
  sreq="Chess; Climbing; Cycling; Hiking;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": memberOf(\"ShawCarol\",net)  ****************"<<endl;
  lres=memberOf("ShawCarol",net);
  sres=toString(lres);
  clear(lres);
  sreq="";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  becomeFriends(\"GoldbergAdele\",\"ShawCarol\",net)  ****************"<<endl;
  bres=becomeFriends("GoldbergAdele","ShawCarol",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  createGroup(\"GoldbergAdele\",\"Running\",net)  ****************"<<endl;
  bres=createGroup("GoldbergAdele","Running",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": groups(net)  ****************"<<endl;
  lres=groups(net);
  sres=toString(lres);
  clear(lres);
  sreq="Chess; Climbing; Cycling; Hiking; Rugby; Running; Swimming;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": memberOf(\"ShawCarol\",net)  ****************"<<endl;
  lres=memberOf("ShawCarol",net);
  sres=toString(lres);
  clear(lres);
  sreq="Running;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;    

  cout<<"*************** Test "<<i<<": memberOf(\"HamiltonMargaret\",net)  ****************"<<endl;
  lres=memberOf("HamiltonMargaret",net);
  sres=toString(lres);
  clear(lres);
  sreq="Chess; Climbing; Cycling; Rugby; Running;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": creatorOf(\"GoldbergAdele\",net)  ****************"<<endl;
  lres=creatorOf("GoldbergAdele",net);
  sres=toString(lres);
  clear(lres);
  sreq="Rugby; Running;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  leaveGroup(\"EasleyAnnie\",\"Swimming\",net)  ****************"<<endl;
  bres=leaveGroup("EasleyAnnie","Swimming",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  leaveGroup(\"EasleyAnnie\",\"Swimming\",net)  ****************"<<endl;
  bres=leaveGroup("EasleyAnnie","Swimming",net);
  breq=false;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": memberOf(\"EasleyAnnie\",net)  ****************"<<endl;
  lres=creatorOf("EasleyAnnie",net);
  sres=toString(lres);
  clear(lres);
  sreq="";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": groups(net)  ****************"<<endl;
  lres=groups(net);
  sres=toString(lres);
  clear(lres);
  sreq="Chess; Climbing; Cycling; Hiking; Rugby; Running;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  joinGroup(\"EasleyAnnie\",\"Swimming\",net)  ****************"<<endl;
  bres=joinGroup("EasleyAnnie","Swimming",net);
  breq=false;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  leaveGroup(\"HamiltonMargaret\",\"Climbing\",net)  ****************"<<endl;
  bres=leaveGroup("HamiltonMargaret","Climbing",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": groups(net)  ****************"<<endl;
  lres=groups(net);
  sres=toString(lres);
  clear(lres);
  sreq="Chess; Cycling; Hiking; Rugby; Running;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": memberOf(\"HamiltonMargaret\",net)  ****************"<<endl;
  lres=memberOf("HamiltonMargaret",net);
  sres=toString(lres);
  clear(lres);
  sreq="Chess; Cycling; Rugby; Running;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": memberOf(\"GoldbergAdele\",net)  ****************"<<endl;
  lres=memberOf("GoldbergAdele",net);
  sres=toString(lres);
  clear(lres);
  sreq="Chess; Cycling; Hiking; Rugby; Running;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": memberOf(\"LovelaceAda\",net)  ****************"<<endl;
  lres=memberOf("LovelaceAda",net);
  sres=toString(lres);
  clear(lres);
  sreq="Chess; Cycling; Hiking;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  deleteMember(\"HopperGrace\",net)  ****************"<<endl;
  bres=deleteMember("HopperGrace",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": members(net)  ****************"<<endl;
  lres=members(net);
  sres=toString(lres);
  clear(lres);
  sreq="AngluinDana; BorgAnita; ConwayLynn; EasleyAnnie; GoldbergAdele; GroszBarbara; HamiltonMargaret; JohnsonKatherine; LovelaceAda; ShawCarol;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  deleteMember(\"HopperGrace\",net)  ****************"<<endl;
  bres=deleteMember("HopperGrace",net);
  breq=false;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": friends(\"GroszBarbara\",net)  ****************"<<endl;
  lres=friends("GroszBarbara",net);
  sres=toString(lres);
  clear(lres);
  sreq="AngluinDana; ConwayLynn;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  createGroup(\"ConwayLynn\",\"Judo\",net)  ****************"<<endl;
  bres=createGroup("ConwayLynn","Judo",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  joinGroup(\"EasleyAnnie\",\"Judo\",net)  ****************"<<endl;
  bres=joinGroup("EasleyAnnie","Judo",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  createGroup(\"GroszBarbara\",\"Taichi\",net)  ****************"<<endl;
  bres=createGroup("GroszBarbara","Taichi",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  joinGroup(\"EasleyAnnie\",\"Taichi\",net)  ****************"<<endl;
  bres=joinGroup("EasleyAnnie","Taichi",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  createGroup(\"EasleyAnnie\",\"Karate\",net)  ****************"<<endl;
  bres=createGroup("EasleyAnnie","Karate",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  joinGroup(\"JohnsonKatherine\",\"Karate\",net)  ****************"<<endl;
  bres=joinGroup("JohnsonKatherine","Karate",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": groups(net)  ****************"<<endl;
  lres=groups(net);
  sres=toString(lres);
  clear(lres);
  sreq="Chess; Cycling; Hiking; Judo; Karate; Rugby; Running; Taichi;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": friends(\"EasleyAnnie\",net)  ****************"<<endl;
  lres=friends("EasleyAnnie",net);
  sres=toString(lres);
  clear(lres);
  sreq="";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  makeMoreFriends(\"EasleyAnnie\",net)  ****************"<<endl;
  bres=makeMoreFriends("EasleyAnnie",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": friends(\"EasleyAnnie\",net)  ****************"<<endl;
  lres=friends("EasleyAnnie",net);
  sres=toString(lres);
  clear(lres);
  sreq="AngluinDana; ConwayLynn; GroszBarbara; JohnsonKatherine;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": friends(\"BorgAnita\",net)  ****************"<<endl;
  lres=friends("BorgAnita",net);
  sres=toString(lres);
  clear(lres);
  sreq="LovelaceAda;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  makeMoreFriends(\"BorgAnita\",net)  ****************"<<endl;
  bres=makeMoreFriends("BorgAnita",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": friends(\"BorgAnita\",net)  ****************"<<endl;
  lres=friends("BorgAnita",net);
  sres=toString(lres);
  clear(lres);
  sreq="AngluinDana; GoldbergAdele; HamiltonMargaret; JohnsonKatherine; LovelaceAda;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  leaveGroup(\"HamiltonMargaret\",\"Running\",net)  ****************"<<endl;
  bres=leaveGroup("HamiltonMargaret","Running",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": friends(\"ShawCarol\",net)  ****************"<<endl;
  lres=friends("ShawCarol",net);
  sres=toString(lres);
  clear(lres);
  sreq="GoldbergAdele;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  makeMoreFriends(\"ShawCarol\",net)  ****************"<<endl;
  bres=makeMoreFriends("ShawCarol",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": friends(\"ShawCarol\",net)  ****************"<<endl;
  lres=friends("ShawCarol",net);
  sres=toString(lres);
  clear(lres);
  sreq="GoldbergAdele;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  deleteMember(\"BorgAnita\",net)  ****************"<<endl;
  bres=deleteMember("BorgAnita",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": members(net)  ****************"<<endl;
  lres=members(net);
  sres=toString(lres);
  clear(lres);
  sreq="AngluinDana; ConwayLynn; EasleyAnnie; GoldbergAdele; GroszBarbara; HamiltonMargaret; JohnsonKatherine; LovelaceAda; ShawCarol;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": groups(net)  ****************"<<endl;
  lres=groups(net);
  sres=toString(lres);
  clear(lres);
  sreq="Chess; Cycling; Hiking; Judo; Karate; Rugby; Running; Taichi;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": friends(\"AngluinDana\",net)  ****************"<<endl;
  lres=friends("AngluinDana",net);
  sres=toString(lres);
  clear(lres);
  sreq="EasleyAnnie; GroszBarbara; LovelaceAda;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": friends(\"GoldbergAdele\",net)  ****************"<<endl;
  lres=friends("GoldbergAdele",net);
  sres=toString(lres);
  clear(lres);
  sreq="HamiltonMargaret; ShawCarol;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": friends(\"HamiltonMargaret\",net)  ****************"<<endl;
  lres=friends("HamiltonMargaret",net);
  sres=toString(lres);
  clear(lres);
  sreq="GoldbergAdele; LovelaceAda;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": friends(\"JohnsonKatherine\",net)  ****************"<<endl;
  lres=friends("JohnsonKatherine",net);
  sres=toString(lres);
  clear(lres);
  sreq="EasleyAnnie;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": friends(\"LovelaceAda\",net)  ****************"<<endl;
  lres=friends("LovelaceAda",net);
  sres=toString(lres);
  clear(lres);
  sreq="AngluinDana; HamiltonMargaret;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;
  
  cout<<"*************** Test "<<i<<":  deleteMember(\"LovelaceAda\",net)  ****************"<<endl;
  bres=deleteMember("LovelaceAda",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": members(net)  ****************"<<endl;
  lres=members(net);
  sres=toString(lres);
  clear(lres);
  sreq="AngluinDana; ConwayLynn; EasleyAnnie; GoldbergAdele; GroszBarbara; HamiltonMargaret; JohnsonKatherine; ShawCarol;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": groups(net)  ****************"<<endl;
  lres=groups(net);
  sres=toString(lres);
  clear(lres);
  sreq="Judo; Karate; Rugby; Running; Taichi;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i; 
  
  cout<<"*************** Test "<<i<<": friends(\"AngluinDana\",net)  ****************"<<endl;
  lres=friends("AngluinDana",net);
  sres=toString(lres);
  clear(lres);
  sreq="EasleyAnnie; GroszBarbara;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": friends(\"HamiltonMargaret\",net)  ****************"<<endl;
  lres=friends("HamiltonMargaret",net);
  sres=toString(lres);
  clear(lres);
  sreq="GoldbergAdele;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": memberOf(\"AngluinDana\",net)  ****************"<<endl;
  lres=memberOf("AngluinDana",net);
  sres=toString(lres);
  clear(lres);
  sreq="Taichi;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": memberOf(\"GoldbergAdele\",net)  ****************"<<endl;
  lres=memberOf("GoldbergAdele",net);
  sres=toString(lres);
  clear(lres);
  sreq="Rugby; Running;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": memberOf(\"HamiltonMargaret\",net)  ****************"<<endl;
  lres=memberOf("HamiltonMargaret",net);
  sres=toString(lres);
  clear(lres);
  sreq="Rugby;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": memberOf(\"JohnsonKatherine\",net)  ****************"<<endl;
  lres=memberOf("JohnsonKatherine",net);
  sres=toString(lres);
  clear(lres);
  sreq="Karate;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  deleteMember(\"GoldbergAdele\",net)  ****************"<<endl;
  bres=deleteMember("GoldbergAdele",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": members(net)  ****************"<<endl;
  lres=members(net);
  sres=toString(lres);
  clear(lres);
  sreq="AngluinDana; ConwayLynn; EasleyAnnie; GroszBarbara; HamiltonMargaret; JohnsonKatherine; ShawCarol;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": groups(net)  ****************"<<endl;
  lres=groups(net);
  sres=toString(lres);
  clear(lres);
  sreq="Judo; Karate; Taichi;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": friends(\"HamoltonMargaret\",net)  ****************"<<endl;
  lres=friends("HamoiltonMargaret",net);
  sres=toString(lres);
  clear(lres);
  sreq="";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": friends(\"ShawCarol\",net)  ****************"<<endl;
  lres=friends("ShawCarol",net);
  sres=toString(lres);
  clear(lres);
  sreq="";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": memberOf(\"HamoltonMargaret\",net)  ****************"<<endl;
  lres=memberOf("HamoiltonMargaret",net);
  sres=toString(lres);
  clear(lres);
  sreq="";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": memberOf(\"ShawCarol\",net)  ****************"<<endl;
  lres=memberOf("ShawCarol",net);
  sres=toString(lres);
  clear(lres);
  sreq="";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  deleteMember(\"ConwayLynn\",net)  ****************"<<endl;
  bres=deleteMember("ConwayLynn",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": members(net)  ****************"<<endl;
  lres=members(net);
  sres=toString(lres);
  clear(lres);
  sreq="AngluinDana; EasleyAnnie; GroszBarbara; HamiltonMargaret; JohnsonKatherine; ShawCarol;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": groups(net)  ****************"<<endl;
  lres=groups(net);
  sres=toString(lres);
  clear(lres);
  sreq="Karate; Taichi;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  deleteMember(\"EasleyAnnie\",net)  ****************"<<endl;
  bres=deleteMember("EasleyAnnie",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": members(net)  ****************"<<endl;
  lres=members(net);
  sres=toString(lres);
  clear(lres);
  sreq="AngluinDana; GroszBarbara; HamiltonMargaret; JohnsonKatherine; ShawCarol;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": groups(net)  ****************"<<endl;
  lres=groups(net);
  sres=toString(lres);
  clear(lres);
  sreq="Taichi;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  deleteMember(\"AngluinDana\",net)  ****************"<<endl;
  bres=deleteMember("AngluinDana",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": members(net)  ****************"<<endl;
  lres=members(net);
  sres=toString(lres);
  clear(lres);
  sreq="GroszBarbara; HamiltonMargaret; JohnsonKatherine; ShawCarol;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": groups(net)  ****************"<<endl;
  lres=groups(net);
  sres=toString(lres);
  clear(lres);
  sreq="Taichi;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  deleteMember(\"GroszBarbara\",net)  ****************"<<endl;
  bres=deleteMember("GroszBarbara",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": members(net)  ****************"<<endl;
  lres=members(net);
  sres=toString(lres);
  clear(lres);
  sreq="HamiltonMargaret; JohnsonKatherine; ShawCarol;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": groups(net)  ****************"<<endl;
  lres=groups(net);
  sres=toString(lres);
  clear(lres);
  sreq="";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  deleteMember(\"JohnsonKatherine\",net)  ****************"<<endl;
  bres=deleteMember("JohnsonKatherine",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": members(net)  ****************"<<endl;
  lres=members(net);
  sres=toString(lres);
  clear(lres);
  sreq="HamiltonMargaret; ShawCarol;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  deleteMember(\"ShawCarol\",net)  ****************"<<endl;
  bres=deleteMember("ShawCarol",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": members(net)  ****************"<<endl;
  lres=members(net);
  sres=toString(lres);
  clear(lres);
  sreq="HamiltonMargaret;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  deleteMember(\"HamiltonMargaret\",net)  ****************"<<endl;
  bres=deleteMember("HamiltonMargaret",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": members(net)  ****************"<<endl;
  lres=members(net);
  sres=toString(lres);
  clear(lres);
  sreq="";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  addMember("F",net);
  addMember("D",net);
  addMember("A",net);
  addMember("E",net);
  addMember("B",net);
  addMember("C",net);
  addMember("J",net);
  addMember("I",net);
  addMember("O",net);
  addMember("H",net);
  addMember("M",net);
  addMember("S",net);
  addMember("G",net);
  addMember("K",net);
  addMember("N",net);
  addMember("Q",net);
  addMember("T",net);
  addMember("L",net);
  addMember("P",net);
  addMember("R",net);

  cout<<"*************** Executing sequence of code:  ****************"<<endl;
  cout<<"--> addMember(\"F\",net)"<<endl;
  cout<<"--> addMember(\"D\",net)"<<endl;
  cout<<"--> addMember(\"A\",ne)t"<<endl;
  cout<<"--> addMember(\"E\",net)"<<endl;
  cout<<"--> addMember(\"B\",net)"<<endl;
  cout<<"--> addMember(\"C\",net)"<<endl;
  cout<<"--> addMember(\"J\",net)"<<endl;
  cout<<"--> addMember(\"I\",net)"<<endl;
  cout<<"--> addMember(\"O\",net)"<<endl;
  cout<<"--> addMember(\"H\",net)"<<endl;
  cout<<"--> addMember(\"M\",net)"<<endl;
  cout<<"--> addMember(\"S\",net)"<<endl;
  cout<<"--> addMember(\"G\",net)"<<endl;
  cout<<"--> addMember(\"K\",net)"<<endl;
  cout<<"--> addMember(\"N\",net)"<<endl;
  cout<<"--> addMember(\"Q\",net)"<<endl;
  cout<<"--> addMember(\"T\",net)"<<endl;
  cout<<"--> addMember(\"L\",net)"<<endl;
  cout<<"--> addMember(\"P\",net)"<<endl;
  cout<<"--> addMember(\"R\",net)"<<endl;
  cout<<"****************** End sequnce of code:  *******************\n"<<endl;

  cout<<"*************** Test "<<i<<": members(net)  ****************"<<endl;
  lres=members(net);
  sres=toString(lres);
  clear(lres);
  sreq="A; B; C; D; E; F; G; H; I; J; K; L; M; N; O; P; Q; R; S; T;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  deleteMember(\"B\",net)  ****************"<<endl;
  bres=deleteMember("B",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": members(net)  ****************"<<endl;
  lres=members(net);
  sres=toString(lres);
  clear(lres);
  sreq="A; C; D; E; F; G; H; I; J; K; L; M; N; O; P; Q; R; S; T;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  deleteMember(\"I\",net)  ****************"<<endl;
  bres=deleteMember("I",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": members(net)  ****************"<<endl;
  lres=members(net);
  sres=toString(lres);
  clear(lres);
  sreq="A; C; D; E; F; G; H; J; K; L; M; N; O; P; Q; R; S; T;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  deleteMember(\"O\",net)  ****************"<<endl;
  bres=deleteMember("O",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": members(net)  ****************"<<endl;
  lres=members(net);
  sres=toString(lres);
  clear(lres);
  sreq="A; C; D; E; F; G; H; J; K; L; M; N; P; Q; R; S; T;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  deleteMember(\"J\",net)  ****************"<<endl;
  bres=deleteMember("J",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": members(net)  ****************"<<endl;
  lres=members(net);
  sres=toString(lres);
  clear(lres);
  sreq="A; C; D; E; F; G; H; K; L; M; N; P; Q; R; S; T;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  deleteMember(\"F\",net)  ****************"<<endl;
  bres=deleteMember("F",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": members(net)  ****************"<<endl;
  lres=members(net);
  sres=toString(lres);
  clear(lres);
  sreq="A; C; D; E; G; H; K; L; M; N; P; Q; R; S; T;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  deleteMember(\"M\",net)  ****************"<<endl;
  bres=deleteMember("M",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": members(net)  ****************"<<endl;
  lres=members(net);
  sres=toString(lres);
  clear(lres);
  sreq="A; C; D; E; G; H; K; L; N; P; Q; R; S; T;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  deleteMember(\"L\",net)  ****************"<<endl;
  bres=deleteMember("L",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": members(net)  ****************"<<endl;
  lres=members(net);
  sres=toString(lres);
  clear(lres);
  sreq="A; C; D; E; G; H; K; N; P; Q; R; S; T;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  deleteMember(\"H\",net)  ****************"<<endl;
  bres=deleteMember("H",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": members(net)  ****************"<<endl;
  lres=members(net);
  sres=toString(lres);
  clear(lres);
  sreq="A; C; D; E; G; K; N; P; Q; R; S; T;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  deleteMember(\"G\",net)  ****************"<<endl;
  bres=deleteMember("G",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": members(net)  ****************"<<endl;
  lres=members(net);
  sres=toString(lres);
  clear(lres);
  sreq="A; C; D; E; K; N; P; Q; R; S; T;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  deleteMember(\"K\",net)  ****************"<<endl;
  bres=deleteMember("K",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": members(net)  ****************"<<endl;
  lres=members(net);
  sres=toString(lres);
  clear(lres);
  sreq="A; C; D; E; N; P; Q; R; S; T;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  deleteMember(\"N\",net)  ****************"<<endl;
  bres=deleteMember("N",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": members(net)  ****************"<<endl;
  lres=members(net);
  sres=toString(lres);
  clear(lres);
  sreq="A; C; D; E; P; Q; R; S; T;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  deleteMember(\"A\",net)  ****************"<<endl;
  bres=deleteMember("A",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": members(net)  ****************"<<endl;
  lres=members(net);
  sres=toString(lres);
  clear(lres);
  sreq="C; D; E; P; Q; R; S; T;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  deleteMember(\"E\",net)  ****************"<<endl;
  bres=deleteMember("E",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": members(net)  ****************"<<endl;
  lres=members(net);
  sres=toString(lres);
  clear(lres);
  sreq="C; D; P; Q; R; S; T;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  deleteMember(\"C\",net)  ****************"<<endl;
  bres=deleteMember("C",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": members(net)  ****************"<<endl;
  lres=members(net);
  sres=toString(lres);
  clear(lres);
  sreq="D; P; Q; R; S; T;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  deleteMember(\"P\",net)  ****************"<<endl;
  bres=deleteMember("P",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": members(net)  ****************"<<endl;
  lres=members(net);
  sres=toString(lres);
  clear(lres);
  sreq="D; Q; R; S; T;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  deleteMember(\"Q\",net)  ****************"<<endl;
  bres=deleteMember("Q",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": members(net)  ****************"<<endl;
  lres=members(net);
  sres=toString(lres);
  clear(lres);
  sreq="D; R; S; T;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  deleteMember(\"R\",net)  ****************"<<endl;
  bres=deleteMember("R",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": members(net)  ****************"<<endl;
  lres=members(net);
  sres=toString(lres);
  clear(lres);
  sreq="D; S; T;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  deleteMember(\"S\",net)  ****************"<<endl;
  bres=deleteMember("S",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": members(net)  ****************"<<endl;
  lres=members(net);
  sres=toString(lres);
  clear(lres);
  sreq="D; T;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  deleteMember(\"T\",net)  ****************"<<endl;
  bres=deleteMember("T",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": members(net)  ****************"<<endl;
  lres=members(net);
  sres=toString(lres);
  clear(lres);
  sreq="D;";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":  deleteMember(\"D\",net)  ****************"<<endl;
  bres=deleteMember("D",net);
  breq=true;
  if(bres==breq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": members(net)  ****************"<<endl;
  lres=members(net);
  sres=toString(lres);
  clear(lres);
  sreq="";
  if(sres==sreq) {
    ++ret;
    cout<<"  Result: PASSED"<<endl;
  }else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"\n--------------------------------------------------"<<endl;
  cout<<"------------> NUMBER OF TESTS PASSED: "<<ret<<"/245"<<endl;
  cout<<"--------------------------------------------------"<<endl;
  return ret;
}

