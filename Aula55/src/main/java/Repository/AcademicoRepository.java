/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Repository;

import Model.Academico;
import org.springframework.data.mongodb.repository.MongoRepository;

/**
 *
 * @author Marcelo Bilobrovec
 */
public interface AcademicoRepository extends MongoRepository<Academico, String> {
    
    
}
