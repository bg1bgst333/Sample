package com.bgstation0.spring.sample.springapplication;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class HomeController {

    @GetMapping("/")
    public String home() {
        return "Fedora-Eclipse-ABCDE";
    }
    
}