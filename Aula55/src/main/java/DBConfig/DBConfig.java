/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package DBConfig;

import Repository.AcademicoRepository;
import Repository.ProfessorRepository;
import com.mongodb.Mongo;
import com.mongodb.MongoClient;
import org.springframework.context.annotation.Configuration;
import org.springframework.data.mongodb.config.AbstractMongoConfiguration;
import org.springframework.data.mongodb.repository.config.EnableMongoRepositories;

/**
 *
 * @author Marcelo Bilobrovec
 */
@Configuration
@EnableMongoRepositories(basePackageClasses = AcademicoRepository.class)

public class DBConfig extends AbstractMongoConfiguration{

    @Override
    protected String getDatabaseName() {
        return "controlacad";
    }

    @Override
    public Mongo mongo() throws Exception {
        MongoClient client = new MongoClient("localhost");
        return client;
    }
    
    
    
}
