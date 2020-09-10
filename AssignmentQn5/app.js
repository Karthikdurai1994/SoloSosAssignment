const express= require("express");
const app = express();
const port = process.env.port || 3000;
class Slots{
    set slotID(ID){
        this.slotId=ID;
    }
    set expertID(expID){
        this.expertId=expID;
    }
    set date(Date){
        this.dat=Date;
    }
    set status(Status){
        this.sta=Status;
    }
    set slotBooking(Slot){
        this.slotBook=Slot;
    }
    set services(Services){
        this.service = Services;
    }
    set price(Price){
        this.pri=Price;
    }
    get slotID(){
        return this.slotId;
    }
    get expertID(){
        return this.expertId;
    }
    get date(){
        return this.dat;
    }
    get status(){
        return this.sta;
    }
    get slotBooking(){
        return this.slotBook;
    }
    get services(){
        return this.service;
    }
    get price(){
        return this.pri;
    }
    constructor(){
    }}
app.get("/", (req, res)=>{
    
        let openSlots=[];
        const csv = require("csvtojson")
        const converter=csv()
        .fromFile('./slots.csv')
        .then((json)=>{
            let e;// Will be an Employee Object
            json.forEach((row)=>{
                if(row.status=="active" && row.isSlotBooked=="FALSE"){
                    e=new Slots();// New Employee Object
                    Object.assign(e,row);// Assign json to the new Employee
                    openSlots.push(e);// Add the Employee to the Array
                }
              
                
            });}).then(()=>{
            // Output the names of the Employees
            res.send(openSlots);
        });  
})
app.listen(port, ()=>{
    console.log("Server Started!!!");
})