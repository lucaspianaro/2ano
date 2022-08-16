package view;

import static Config.Config.ALTERAR;
import static Config.Config.EXCLUIR;
import static Config.Config.INCLUIR;
import static DAO.DAO.academicoRepository;
import Model.Academico;
import Utility.XPopOver;
import de.jensd.fx.glyphs.materialdesignicons.MaterialDesignIconView;
import java.net.URL;
import java.util.ResourceBundle;
import javafx.beans.binding.Bindings;
import javafx.collections.FXCollections;
import javafx.event.Event;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.TableView;
import org.springframework.data.domain.Sort;

public class AcademicoController implements Initializable {

    public char acao;
    public Academico academico;

    @FXML
    public TableView<Academico> tblvwAcademicos;

    @FXML
    private MaterialDesignIconView btnInclusao;

    @FXML
    private MaterialDesignIconView btnAlteracao;

    @FXML
    private MaterialDesignIconView btnExclusao;

    @FXML
    private void btnInclusaoClick(Event event) {
        acao = INCLUIR;
        academico = new Academico();
        showCRUD();
    }

    @FXML
    private void btnAlteracaoClick(Event event) {
        acao = ALTERAR;
        academico = tblvwAcademicos.getSelectionModel().getSelectedItem();
        showCRUD();
    }

    @FXML
    private void btnExclusaoClick(Event event) {
        acao = EXCLUIR;
        academico = tblvwAcademicos.getSelectionModel().getSelectedItem();
        showCRUD();
    }

    private void showCRUD() {
        String cena = "/fxml/CRUDAcademico.fxml";
        XPopOver popOver = null;

        switch (acao) {
            case INCLUIR:
                popOver = new XPopOver(cena, "Inclusão de Acadêmico", null);
                break;
            case ALTERAR:
                popOver = new XPopOver(cena, "Alteração de Acadêmico", null);
                break;
            case EXCLUIR:
                popOver = new XPopOver(cena, "Exclusão de Acadêmico", null);
                break;
        }
        CRUDAcademicoController controller = popOver.getLoader().getController();
        controller.setCadastroController(this);
    }

    @Override
    public void initialize(URL url, ResourceBundle rb) {

        tblvwAcademicos.setItems(FXCollections.observableList(academicoRepository.findAll(new Sort(new Sort.Order("nome")))));

        btnAlteracao.visibleProperty().bind(Bindings.isEmpty((tblvwAcademicos.getSelectionModel().getSelectedItems())).not());
        btnExclusao.visibleProperty().bind(btnAlteracao.visibleProperty());

    }
}
