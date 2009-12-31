import java.lang.reflect.Method;

import net.sf.cglib.core.ClassGenerator;
import net.sf.cglib.core.DefaultGeneratorStrategy;
import net.sf.cglib.proxy.*;
import net.sf.cglib.transform.TransformingClassGenerator;
import net.sf.cglib.transform.impl.AddPropertyTransformer;

import org.objectweb.asm.Type;

public class TestCGLib implements MethodInterceptor {
    public static void main(String[] args) throws Exception {
        Enhancer e = new Enhancer();
        e.setSuperclass(Object.class);
        e.setCallback(new TestCGLib());
        e.setStrategy(new DefaultGeneratorStrategy() {
            protected ClassGenerator transform(ClassGenerator cg) {
                return new TransformingClassGenerator(
                        cg,
                        new AddPropertyTransformer(
                                new String[] { "XX" },//这个地方根据你的Xml来构造相应的名称和类型
                                new Type[] { Type.INT_TYPE }
                        )
                );
            }
        });
        Object object = e.create();
        System.out.println(object.getClass().getMethod("setXX", new Class[]{int.class}).invoke(object, 123));//.getMethod("settestint", new Class[]{int.class}).invoke(o, 123));
        System.out.println(object.getClass().getMethod("getXX").invoke(object));
    }

    public Object intercept(Object obj, Method method, Object[] arg, MethodProxy proxy) throws Throwable {
        return null;
    }
}
