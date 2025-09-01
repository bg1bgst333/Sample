package com.bgstation0.spring.sample.agm;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class MultiUrlController {

    @GetMapping("/abc")
    public String abc() {
        return "Hello abc";
    }

    @GetMapping("/xyz")
    public String xyz() {
        return "Hello xyz";
    }
    
}
