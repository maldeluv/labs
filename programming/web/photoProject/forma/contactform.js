jQuery(document).ready(function($) {

    $(".ajax-contact-form").submit(function() {
        var str = $(this).serialize();

        $.ajax({
            type: "POST",
            url: "http://C:/program%20files%20(x86)/ospanel/domains/forms/contact.php",
            data: str,
            success: function(msg) {
                if(msg == 'OK') {
                    result = '<p>Ваш заказ принят</p>';
                    $(".fields").hide();
                } else {
                    result = msg;
                }
                $('.note').html(result);
            }
        });
        return false;
    });
});