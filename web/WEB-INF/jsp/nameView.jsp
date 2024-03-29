<%-- 
    Document   : nameView
    Created on : 2014. 6. 10, 오후 9:24:23
    Author     : Robby
--%>
<%@taglib uri="http://www.springframework.org/tags" prefix="spring" %>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
        <script src="//ajax.googleapis.com/ajax/libs/jquery/1.11.0/jquery.min.js"></script>
        <script>
          $(document).ready(function() {
            $('#submit').click(function() {
//              var data = {
//                Name: $('#name').val()             
//              };
               var name = $('#name').val();
               
//              console.log(data);
              
              $.ajax({
                type: 'POST',
                url: './helloView.jsp',
                async: true,
                data: "name=" + name,
                success: function(response) {
                  //window.location.replace('./confirm.html');
                   console.log(response);
                },
                error: function(error_msg) {
                   console.log("error: "+ error_msg);                  
                }
              });
            });
          });

        </script>
    </head>
    <body>
        <h1> Enter Your Name.</h1>
        
        <spring:nestedPath path="name">
            <form action="" method="post">
                Name:
                <spring:bind path="value">
                    <input id="name" type="text" name="${status.expression}" value="${status.value}">
                </spring:bind>
                <input id="submit" type="submit" value="OK">
            </form>
        </spring:nestedPath>
    </body>
</html>
                                                 