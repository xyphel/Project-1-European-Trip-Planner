
// LOGIN PAGE

const form = document.getElementById('form');
const username = document.getElementById('username');
const password = document.getElementById('password');

function whenSubmit(){

    if(password.value === 'admin' && username.value === 'admin'){
        document.location.href='index.html';
    }else if(password.value == 'user' && username.value === 'user'){
        document.location.href='form/user.html';
    }else{
        //alert("Incorrect Input");
    }
}
form.addEventListener('submit', function(e){
    whenSubmit();
})

// Highlights the box green and displays message
function showError(input, message){

    const formControl = input.parentElement;

    formControl.className = 'form-control error';

    const small = formControl.querySelector('small');

    small.innerText = message;

}

// Highlights the box green and displays message
function showSuccess(input){

    formControl = input.parentElement;

    formControl.className = 'form-control success'

}

// Get Field Name
function getFieldName(input){
    return input.id;
}


// Event Listener
form.addEventListener('submit', function(e){
    e.preventDefault();

    // Checks the user input
    if(username.value ===''){
        showError(username, 'Enter Username');
    } else if(username.value !== 'user' && username.value !== 'admin'){
        showError(username, 'Invalid Username');
    }else {
        showSuccess(username);
    }


    // Checks the password input
    if(password.value ===''){
        showError(password, 'Enter password');
    } else if(password.value !== 'user' && password.value !== 'admin')
    {
        showError(password, 'Invalid Password');
    }
    else {
        showSuccess(password);
    }



})
























