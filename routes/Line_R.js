const express = require("express");
const router = express.Router()
module.exports = router;


const lineModel = require("../models/Line_M");


//to client
router.get('/Add',async(req, res) => {   
    res.render("addInfo", {pageTitle:"Add Parameters: ",
       item:{} 
    });
});
//to server
router.post('/Add',(req, res) => {
    const modelData = new lineModel({
        duration:req.body.duration,
        lightLvl:req.body.lightLvl        
    });
    modelData.save();
    res.redirect("/List");
});

router.get('/List',async (req, res) => {
    let infoData=await lineModel.find();   
    res.render("LineAPI", {pageTitle:"manage information",
    data:infoData
    });
});



router.get('/Edit',async (req, res) => {
    let item_data=await lineModel.find();
    res.render("addInfo", {pageTitle:"Update information",
        item:item_data
    });
});

router.post('/Edit',async (req, res) => {
    const modelData = {
        duration:req.body.duration,
        lightLvl:req.body.lightLvl       
    }
    let item_data=await lineModel.findByIdAndUpdate(req.query.id,modelData);
    res.redirect("/R/List");
});

//delete info GET
router.get('/Delete',async (req, res) => {
    let item_data=await lineModel.findByIdAndDelete(req.query.id);
    res.redirect("/R/List");
});

//delete info from DB
router.post('/Delete',async (req, res) => {
    let item_data=await lineModel.findByIdAndDelete(req.body.id);
    res.redirect("/R/List");
});





    









