package com.bgstation0.spring.sample.asba;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@SpringBootApplication
public class AsbaApplication {

	public static void main(String[] args) {
		SpringApplication.run(AsbaApplication.class, args);
	}

}

@RestController
@RequestMapping("/")
class HomeController {
    @GetMapping
    public String home() {
        return "ABCDE";
    }
}
