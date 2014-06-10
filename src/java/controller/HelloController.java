/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package controller;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.springframework.validation.BindException;
import org.springframework.web.servlet.ModelAndView;
import org.springframework.web.servlet.mvc.SimpleFormController;



import org.springframework.stereotype.Controller;  
import org.springframework.web.bind.annotation.RequestMapping;  
import org.springframework.web.bind.annotation.RequestParam;  
import org.springframework.web.bind.annotation.ResponseBody;

import service.HelloService;

/**
 *
 * @author Robby
 */
public class HelloController extends SimpleFormController {
    
    private HelloService helloService;
    
    public HelloController() {
        //Initialize controller properties here or 
        //in the Web Application Context

        setCommandClass(Name.class);
        setCommandName("name");
        setSuccessView("helloView");
        setFormView("nameView");
    }
    
    public void setHelloService(HelloService helloService) {
        this.helloService = helloService;
    }
    
//   @Override    
//    protected void doSubmitAction(Object command) throws Exception {
//        throw new UnsupportedOperationException("Not yet implemented");
//    }

    //Use onSubmit instead of doSubmitAction 
    //when you need access to the Request, Response, or BindException objects
    
     @Override
        protected ModelAndView onSubmit(
                    HttpServletRequest request,
                    HttpServletResponse response,
                    Object command,
                    BindException errors) throws Exception {

                Name name = (Name) command;
                ModelAndView mv = new ModelAndView(getSuccessView());
                mv.addObject("helloMessage", helloService.sayHello(name.getValue()));
                return mv;
        }
     
}
