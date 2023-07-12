const mongoose = require('mongoose');


const dataSchema = new mongoose.Schema({ 
    
    duration:{
        required: true,
        type: Number
    },
    lightLvl:{
        require: true,
        type: Number,
    },
    heat:{
        require: false,
        type: Number,
    },
    hold:{
        require: false,
        type: Number,
    }
});

module.exports = mongoose.model('lineProduction', dataSchema)