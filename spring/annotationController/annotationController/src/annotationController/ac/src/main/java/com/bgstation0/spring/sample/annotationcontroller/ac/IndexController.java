package com.bgstation0.spring.sample.annotationcontroller.ac;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;

@Controller
public class IndexController {

    @GetMapping("/")
    public String index() {
        return "index";  // templates/index.htmlを返す.
    }
    
}
